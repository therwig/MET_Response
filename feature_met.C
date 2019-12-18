#define feature_met_cxx
#include "feature_met.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void feature_met::Loop()
{
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   class T
   {
    public:

        float ge;
        float pf;
        float pu;

        T(float a, float b, float c) { ge = a; pf = b; pu = c;}

        static bool comp(const T &t1, const T &t2)
        {
            return (t1.ge > t2.ge);
        }
   };

      vector<T> vGe;

      vGe.clear();

      const int bin = 20;

      float mini = 0;
      float medi = 100;
      float maxi = 200;

      TH1F *hGe[bin];
      TH1F *hPF[bin];
      TH1F *hPu[bin];

      char nameGe[20];
      char namePF[20];
      char namePu[20];
      char titleGe[100];
      char titlePF[100];
      char titlePu[100];

      float binning_gr = (maxi - medi)/(bin/2);
      float binning_le = (medi - mini)/(bin/2);

      /// Define histograms by each MET region
      for (int i = 0 ; i < bin/2 ; i++)
      {
        sprintf(nameGe, "hGe%d", i);
        sprintf(namePF, "hPF%d", i);
        sprintf(namePu, "hPu%d", i);
        sprintf(titleGe, "hGe%d range", i);
        sprintf(titlePF, "hPF%d range", i);
        sprintf(titlePu, "hPu%d range", i);
        hGe[i]= new TH1F(nameGe, titleGe, 100, mini+(i*binning_le), mini+((i+1)*binning_le));
        hPF[i]= new TH1F(namePF, titlePF, 100, mini+(i*binning_le), mini+((i+1)*binning_le));
        hPu[i]= new TH1F(namePu, titlePu, 100, mini+(i*binning_le), mini+((i+1)*binning_le));
      }
      for (int i = bin/2 ; i < bin ; i++)
      {
        sprintf(nameGe, "hGe%d", i);
        sprintf(namePF, "hPF%d", i);
        sprintf(namePu, "hPu%d", i);
        sprintf(titleGe, "hGe%d range", i);
        sprintf(titlePF, "hPF%d range", i);
        sprintf(titlePu, "hPu%d range", i);
        hGe[i]= new TH1F(nameGe, titleGe, 100, medi+((i - (bin/2))*binning_gr), medi+(((i - (bin/2)+1)*binning_gr)));
        hPF[i]= new TH1F(namePF, titlePF, 100, medi+((i - (bin/2))*binning_gr), medi+(((i - (bin/2)+1)*binning_gr)));
        hPu[i]= new TH1F(namePu, titlePu, 100, medi+((i - (bin/2))*binning_gr), medi+(((i - (bin/2)+1)*binning_gr)));
      }


   Long64_t nbytes = 0;
   Long64_t nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      float pfmet = L1PFMet_pt;
      float pfmet_phi = L1PFMet_phi;

      float pumet = L1PuppiMet_pt;
      float pumet_phi = L1PuppiMet_phi;

      float gemet = genMet_pt;
      float gemet_phi = genMet_phi;

      float pfge_res = pfmet/gemet;
      float puge_res = pumet/gemet;

      /// Store the Gen, PF and Puppi MET
      vGe.push_back(T(gemet, pfmet, pumet));

   }

   float aGemet_Mean[bin];
   float aPFmet_Mean[bin];
   float aPumet_Mean[bin];

   /// Fill the histograms in each MET range
   for(int i = 0 ; i < bin/2; i++)
   {
       for (int j = 0 ; j < vGe.size() ; j++)
       {

           if( vGe[j].ge > mini + (i * binning_le) && vGe[j].ge <= mini + ( (i+1) * binning_le) )
           {
                hGe[i]->Fill(vGe[j].ge);
           }
           if( vGe[j].pf > mini + (i * binning_le) && vGe[j].pf <= mini + ( (i+1) * binning_le) )
           {
                hPF[i]->Fill(vGe[j].pf);
           }
           if( vGe[j].pu > mini + (i * binning_le) && vGe[j].pu <= mini + ( (i+1) * binning_le) )
           {
                hPu[i]->Fill(vGe[j].pu);
           }
       }
   }
   for(int i = bin/2 ; i < bin; i++)
   {
       for (int j = 0 ; j < vGe.size() ; j++)
       {

           if( vGe[j].ge > medi + ((i - (bin/2)) * binning_gr) && vGe[j].ge <= medi + ( ((i - (bin/2))+1) * binning_gr) )
           {
                hGe[i]->Fill(vGe[j].ge);
           }
           if( vGe[j].pf > medi + ((i - (bin/2)) * binning_gr) && vGe[j].pf <= medi + ( ((i - (bin/2))+1) * binning_gr) )
           {
                hPF[i]->Fill(vGe[j].pf);
           }
           if( vGe[j].pu > medi + ((i - (bin/2)) * binning_gr) && vGe[j].pu <= medi + ( ((i - (bin/2))+1) * binning_gr) )
           {
                hPu[i]->Fill(vGe[j].pu);
           }
       }
   }

   /// Store all histograms
    TFile *ff = new TFile("./plots_resp/feature/hists/response_feature_VBF.root", "RECREATE");

    for(int i = 0 ; i < bin ; i++)
    {
        hGe[i]->Write();
        hPF[i]->Write();
        hPu[i]->Write();
    }

    ff->Close();

    float aErGE[bin];
    float aErPF[bin];
    float aErPu[bin];
    float aErrF[bin];
    float aErrU[bin];

   for(int i = 0 ; i < bin ; i++)
   {
        /// Store mean value
        aGemet_Mean[i] = hGe[i]->GetMean();
        aPFmet_Mean[i] = hPF[i]->GetMean();
        aPumet_Mean[i] = hPu[i]->GetMean();

        /// Calculate the errors from error propagation
        aErGE[i] = sqrt(hGe[i]->GetMeanError())/hGe[i]->GetMean();
        aErPF[i] = sqrt(hPF[i]->GetMeanError())/hPF[i]->GetMean();
        aErPu[i] = sqrt(hPu[i]->GetMeanError())/hPu[i]->GetMean();

        aErrF[i] = (hPF[i]->GetMean()/hGe[i]->GetMean())*sqrt( pow(aErPF[i], 2) + pow(aErGE[i], 2));
        aErrU[i] = (hPu[i]->GetMean()/hGe[i]->GetMean())*sqrt( pow(aErPu[i], 2) + pow(aErGE[i], 2));
    }

    float aPF_res[bin];
    float aPu_res[bin];

    /// Get the reponse value
    cout << "\t\tRange\t\t"<<"|\t"<<"PF resp\t"<<"|\t"<<"Puppi resp\t"<<endl;
    for(int i = 0 ; i < bin/2 ; i++)
    {
        aPF_res[i] = aPFmet_Mean[i]/aGemet_Mean[i];
        aPu_res[i] = aPumet_Mean[i]/aGemet_Mean[i];
        cout <<"\t" <<setprecision(5)<<mini + (i * binning_le) << " < MET <= "<<setprecision(5)<<mini + ( (i+1) * binning_le)<<"\t|\t"<<setprecision(5)<<aPF_res[i]<<"\t|\t"<<setprecision(5)<<aPu_res[i]<<endl;
    }
    for(int i = bin/2 ; i < bin ; i++)
    {
        aPF_res[i] = aPFmet_Mean[i]/aGemet_Mean[i];
        aPu_res[i] = aPumet_Mean[i]/aGemet_Mean[i];
        cout <<"\t" <<setprecision(5)<<medi + ((i - (bin/2)) * binning_gr) << " < MET <= "<<setprecision(5)<<medi + ( ((i - (bin/2))+1) * binning_gr)<<"\t|\t"<<setprecision(5)<<aPF_res[i]<<"\t|\t"<<setprecision(5)<<aPu_res[i]<<endl;
    }

    /// Check the errors
        cout << "PF errors"<<endl;
    for (int i = 0 ; i < bin ; i++)
    {
        cout << i << "th error: "<<aErrF[i] <<endl;
    }
        cout << "Puppi errors"<<endl;
    for (int i = 0 ; i < bin ; i++)
    {
        cout << i << "th error: "<<aErrU[i] <<endl;
    }

   /// Draw plot
   TCanvas *c1 = new TCanvas("c1", "", 500, 500);

   TFile *fout = new TFile("./plots_resp/feature/figure/response_feature_VBF.root", "RECREATE");

   TGraphErrors *gPF_res = new TGraphErrors(bin, aGemet_Mean, aPF_res, 0, aErrF);
   TGraphErrors *gPu_res = new TGraphErrors(bin, aGemet_Mean, aPu_res, 0, aErrU);

   TLegend *lg = new TLegend(0.3875502,0.1481697,0.8880522,0.2893666,NULL,"brNDC");

    gPF_res->SetMarkerStyle(20);
    gPu_res->SetMarkerStyle(20);
    gPF_res->SetLineColor(kBlue);
    gPu_res->SetLineColor(kRed);
    gPF_res->SetLineWidth(3);
    gPu_res->SetLineWidth(3);

    lg->AddEntry(gPF_res, "PF MET Response", "l");
    lg->AddEntry(gPu_res, "Puppi MET Response", "l");

    gPF_res->GetXaxis()->SetTitle("Gen MET (GeV)");
    gPF_res->GetYaxis()->SetTitle("<Reco MET>/<Gen MET>");
    gPF_res->GetYaxis()->SetRangeUser(0.5, 1.1);

    gPF_res->Draw("APL");
    gPu_res->Draw("PLSAME");

    lg->SetLineWidth(0);
    lg->Draw();

    c1->Print("./plots_resp/feature/figure/response_feature_VBF.pdf");

    gPF_res->Write();
    gPu_res->Write();
    fout->Close();

}
