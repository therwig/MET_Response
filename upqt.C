#define upqt_cxx
#include "upqt.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void upqt::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   class T
   {
    public:

        float px;
        float py;
        float phi;

        T(float a, float b, float c) { px = a; py = b; phi = c;}

        static bool comp(const T &t1, const T &t2)
        {
            return (t1.px > t2.px);
        }
   };

      vector<T> vQt;
      vector<T> vPF;
      vector<T> vQU;

      vQU.clear();

      const int bin = 20;

      float mini = 0;
      float maxi = 200;

      TH1F *hGe[bin];
      TH1F *hPF[bin];

      char nameGe[20];
      char namePF[20];
      char titleGe[100];
      char titlePF[100];

      float binning_le = (maxi - mini)/(bin);

      for (int i = 0 ; i < bin ; i++)
      {
        sprintf(nameGe, "hGe%d", i);
        sprintf(namePF, "hPF%d", i);
        sprintf(titleGe, "hGe%d range", i);
        sprintf(titlePF, "hPF%d range", i);
        hGe[i]= new TH1F(nameGe, titleGe, 100, mini+(i*binning_le), mini+((i+1)*binning_le));
        hPF[i]= new TH1F(namePF, titlePF, 100, (mini-((i+1)*binning_le)), (mini-(i*binning_le)));
      }


   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<50;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      vQt.clear();
      vPF.clear();

      if (nPFMu != 2) continue; /// Select events which have two muons

      for(int i = 0 ; i < nPFCandidate ; i ++)
      {

        float pfcandi_pt  = PFCandidate_pt[i];
        float pfcandi_eta = PFCandidate_eta[i];
        float pfcandi_phi = PFCandidate_phi[i];

        if(pfcandi_phi <= 0.) pfcandi_phi += 2.*TMath::Pi();

        float px = pfcandi_pt*TMath::Cos(pfcandi_phi);
        float py = pfcandi_pt*TMath::Sin(pfcandi_phi);

        if (abs(PFCandidate_pdgId[i]) != 13)  /// Select the candidates except for muon
        {
        vPF.push_back(T(px, py, pfcandi_phi));
        }
        if (abs(PFCandidate_pdgId[i]) == 13)  /// Select the two muons
        {
        vQt.push_back(T(px, py, pfcandi_phi));
        }
      }

   float ux = 0.;
   float uy = 0.;

   for(int i = 0 ; i < vPF.size(); i ++)   /// Sum of all PF candidates except for PF muons
   {
    ux += vPF[i].px;
    uy += vPF[i].py;
   }


   float qx = 0.;
   float qy = 0.;

   for(int i = 0 ; i < vQt.size(); i ++)  /// Sum of muons = pT(Z)
   {
    qx += vQt[i].px;
    qy += vQt[i].py;
   }

   /// Angle between pT(Z) and x-axis
   float ang = 0;

   if (qx > 0. && qy < 0.)
   {
        ang = 2*TMath::Pi() + TMath::ATan(qy/qx);
   } else if (qx < 0. && qy > 0.)
   {
        ang = TMath::Pi() + TMath::ATan(qy/qx);
   } else if (qx < 0. && qy < 0.)
   {
        ang = TMath::Pi() + TMath::ATan(qy/qx);
   } else {
        ang = TMath::ATan(qy/qx);
   }

   float qt = sqrt(qx*qx + qy*qy);   /// Get qT

   float up = ux*TMath::Cos(ang) - uy*TMath::Sin(ang);  /// Get u-parallel laid on the rotated axis
   float ut = ux*TMath::Sin(ang) + uy*TMath::Cos(ang);  /// Get u-perpendicular laid on the retated axis

   /// Store the kinematics information
   vQU.push_back(T(qt, up, ut));
}

   float aGemet_Mean[bin];
   float aPFmet_Mean[bin];

   /// Fill the histograms for each MET range (Here "vQU[j].px" is qT and "vQU[j].py" is u-parallel)
   for(int i = 0 ; i < bin; i++)
   {
       for (int j = 0 ; j < vQU.size() ; j++)
       {

           if( vQU[j].px > mini + (i * binning_le) && vQU[j].px <= mini + ( (i+1) * binning_le) )
           {
                hGe[i]->Fill(vQU[j].px);
           }
           if( vQU[j].py <= mini - (i * binning_le) && vQU[j].py > mini - ( (i+1) * binning_le) )
           {
                hPF[i]->Fill(vQU[j].py);
           }
       }
   }

    /// Store all histograms
    TFile *ff = new TFile("./plots_resp/upqt/hists/response_upqt_DY.root", "RECREATE");

    for(int i = 0 ; i < bin ; i++)
    {
        hGe[i]->Write();
        hPF[i]->Write();
    }

    ff->Close();

    float aErGE[bin];
    float aErPF[bin];
    float aErrF[bin];

    for(int i = 0 ; i < bin ; i++)
    {
        /// Store mean value
        aGemet_Mean[i] = hGe[i]->GetMean();
        aPFmet_Mean[i] = hPF[i]->GetMean();

        /// Calculate the errors from error propagation
        aErGE[i] = sqrt(hGe[i]->GetMeanError())/hGe[i]->GetMean();
        aErPF[i] = sqrt(hPF[i]->GetMeanError())/hPF[i]->GetMean();

        aErrF[i] = -(hPF[i]->GetMean()/hGe[i]->GetMean())*sqrt( pow(aErPF[i], 2) + pow(aErGE[i], 2));
    }

    float aPF_res[bin];


    /// Get the respones values
    cout << "\t\tRange\t\t"<<"|\t"<<"PF resp\t"<<endl;
    for(int i = 0 ; i < bin ; i++)
    {
        aPF_res[i] = -(aPFmet_Mean[i]/aGemet_Mean[i]);
    cout <<"\t" <<setprecision(5)<<mini + (i * binning_le) << " < qt <= "<<setprecision(5)<<mini + ( (i+1) * binning_le)<<"\t|\t"<<setprecision(5)<<aPF_res[i]<<endl;
    }

    /// Check the errors
        cout << "PF errors"<<endl;
    for (int i = 0 ; i < bin ; i++)
    {
        cout << i << "th error: "<<aErrF[i] <<endl;
    }

    /// Draw plot 
    TCanvas *c1 = new TCanvas("c1", "", 500, 500);

    TFile *fout = new TFile("./plots_resp/upqt/figure/response_upqt_DY.root", "RECREATE");

    TGraphErrors *gPF_res = new TGraphErrors(bin, aGemet_Mean, aPF_res, 0, aErrF);

    TLegend *lg = new TLegend(0.3875502,0.1481697,0.8880522,0.2893666,NULL,"brNDC");

    gPF_res->SetMarkerStyle(20);
    gPF_res->SetLineColor(kBlue);
    gPF_res->SetLineWidth(3);

    lg->AddEntry(gPF_res, "PF MET Response", "l");

    gPF_res->GetXaxis()->SetTitle("q_{T} [GeV]");
    gPF_res->GetXaxis()->SetTitleSize(0.05);
    gPF_res->GetXaxis()->SetTitleOffset(0.86);
    gPF_res->GetYaxis()->SetTitle("-<u_{||}>/<q_{T}>");
    gPF_res->GetYaxis()->SetTitleSize(0.05);
    gPF_res->GetYaxis()->SetTitleOffset(0.86);
    gPF_res->GetYaxis()->SetRangeUser(0.5, 1.1);

    gPF_res->Draw("APL");

    lg->SetLineWidth(0);
    lg->Draw();

    c1->Print("./plots_resp/upqt/figure/response_DY.pdf");

    gPF_res->Write();
    fout->Close();

}
