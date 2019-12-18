//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Dec 18 16:59:00 2019 by ROOT version 6.14/04
// from TTree Events/Events
// found on file: perfNano_DY_M50_300k.root
//////////////////////////////////////////////////////////

#ifndef upqt_h
#define upqt_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class upqt {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   UInt_t          nGenJets;
   Float_t         GenJets_pt[13];   //[nGenJets]
   Float_t         GenJets_eta[13];   //[nGenJets]
   Float_t         GenJets_phi[13];   //[nGenJets]
   Float_t         GenJets_mass[13];   //[nGenJets]
   UInt_t          nL1CaloJets;
   Float_t         L1CaloJets_pt[118];   //[nL1CaloJets]
   Float_t         L1CaloJets_eta[118];   //[nL1CaloJets]
   Float_t         L1CaloJets_phi[118];   //[nL1CaloJets]
   Float_t         L1CaloJets_mass[118];   //[nL1CaloJets]
   Float_t         L1CaloJets_genpt[118];   //[nL1CaloJets]
   Float_t         L1CaloJets_gendr[118];   //[nL1CaloJets]
   UInt_t          nL1PFJets;
   Float_t         L1PFJets_pt[121];   //[nL1PFJets]
   Float_t         L1PFJets_eta[121];   //[nL1PFJets]
   Float_t         L1PFJets_phi[121];   //[nL1PFJets]
   Float_t         L1PFJets_mass[121];   //[nL1PFJets]
   Float_t         L1PFJets_genpt[121];   //[nL1PFJets]
   Float_t         L1PFJets_gendr[121];   //[nL1PFJets]
   UInt_t          nL1PuppiJets;
   Float_t         L1PuppiJets_pt[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_eta[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_phi[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_mass[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_genpt[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_gendr[23];   //[nL1PuppiJets]
   Float_t         L1CaloMetBarrel_pt;
   Float_t         L1CaloMetBarrel_phi;
   Float_t         L1CaloMetBarrel_para;
   Float_t         L1CaloMetBarrel_perp;
   Float_t         L1PFMetBarrel_pt;
   Float_t         L1PFMetBarrel_phi;
   Float_t         L1PFMetBarrel_para;
   Float_t         L1PFMetBarrel_perp;
   Float_t         L1PuppiMetBarrel_pt;
   Float_t         L1PuppiMetBarrel_phi;
   Float_t         L1PuppiMetBarrel_para;
   Float_t         L1PuppiMetBarrel_perp;
   Float_t         genMetBarrel_pt;
   Float_t         genMetBarrel_phi;
   Float_t         L1CaloMetCentral_pt;
   Float_t         L1CaloMetCentral_phi;
   Float_t         L1CaloMetCentral_para;
   Float_t         L1CaloMetCentral_perp;
   Float_t         L1PFMetCentral_pt;
   Float_t         L1PFMetCentral_phi;
   Float_t         L1PFMetCentral_para;
   Float_t         L1PFMetCentral_perp;
   Float_t         L1PuppiMetCentral_pt;
   Float_t         L1PuppiMetCentral_phi;
   Float_t         L1PuppiMetCentral_para;
   Float_t         L1PuppiMetCentral_perp;
   Float_t         genMetCentral_pt;
   Float_t         genMetCentral_phi;
   Float_t         L1CaloMet_pt;
   Float_t         L1CaloMet_phi;
   Float_t         L1CaloMet_para;
   Float_t         L1CaloMet_perp;
   Float_t         L1PFMet_pt;
   Float_t         L1PFMet_phi;
   Float_t         L1PFMet_para;
   Float_t         L1PFMet_perp;
   Float_t         L1PuppiMet_pt;
   Float_t         L1PuppiMet_phi;
   Float_t         L1PuppiMet_para;
   Float_t         L1PuppiMet_perp;
   Float_t         genMet_pt;
   Float_t         genMet_phi;
   UInt_t          nPFCandidate;
   Float_t         PFCandidate_eta[296];   //[nPFCandidate]
   Float_t         PFCandidate_mass[296];   //[nPFCandidate]
   Float_t         PFCandidate_phi[296];   //[nPFCandidate]
   Float_t         PFCandidate_pt[296];   //[nPFCandidate]
   Float_t         PFCandidate_vz[296];   //[nPFCandidate]
   Int_t           PFCandidate_charge[296];   //[nPFCandidate]
   Int_t           PFCandidate_pdgId[296];   //[nPFCandidate]
   UInt_t          nPFMu;
   Float_t         PFMu_eta[5];   //[nPFMu]
   Float_t         PFMu_mass[5];   //[nPFMu]
   Float_t         PFMu_phi[5];   //[nPFMu]
   Float_t         PFMu_pt[5];   //[nPFMu]
   Float_t         PFMu_vz[5];   //[nPFMu]
   Int_t           PFMu_charge[5];   //[nPFMu]
   Int_t           PFMu_quality[5];   //[nPFMu]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nGenJets;   //!
   TBranch        *b_GenJets_pt;   //!
   TBranch        *b_GenJets_eta;   //!
   TBranch        *b_GenJets_phi;   //!
   TBranch        *b_GenJets_mass;   //!
   TBranch        *b_nL1CaloJets;   //!
   TBranch        *b_L1CaloJets_pt;   //!
   TBranch        *b_L1CaloJets_eta;   //!
   TBranch        *b_L1CaloJets_phi;   //!
   TBranch        *b_L1CaloJets_mass;   //!
   TBranch        *b_L1CaloJets_genpt;   //!
   TBranch        *b_L1CaloJets_gendr;   //!
   TBranch        *b_nL1PFJets;   //!
   TBranch        *b_L1PFJets_pt;   //!
   TBranch        *b_L1PFJets_eta;   //!
   TBranch        *b_L1PFJets_phi;   //!
   TBranch        *b_L1PFJets_mass;   //!
   TBranch        *b_L1PFJets_genpt;   //!
   TBranch        *b_L1PFJets_gendr;   //!
   TBranch        *b_nL1PuppiJets;   //!
   TBranch        *b_L1PuppiJets_pt;   //!
   TBranch        *b_L1PuppiJets_eta;   //!
   TBranch        *b_L1PuppiJets_phi;   //!
   TBranch        *b_L1PuppiJets_mass;   //!
   TBranch        *b_L1PuppiJets_genpt;   //!
   TBranch        *b_L1PuppiJets_gendr;   //!
   TBranch        *b_L1CaloMetBarrel_pt;   //!
   TBranch        *b_L1CaloMetBarrel_phi;   //!
   TBranch        *b_L1CaloMetBarrel_para;   //!
   TBranch        *b_L1CaloMetBarrel_perp;   //!
   TBranch        *b_L1PFMetBarrel_pt;   //!
   TBranch        *b_L1PFMetBarrel_phi;   //!
   TBranch        *b_L1PFMetBarrel_para;   //!
   TBranch        *b_L1PFMetBarrel_perp;   //!
   TBranch        *b_L1PuppiMetBarrel_pt;   //!
   TBranch        *b_L1PuppiMetBarrel_phi;   //!
   TBranch        *b_L1PuppiMetBarrel_para;   //!
   TBranch        *b_L1PuppiMetBarrel_perp;   //!
   TBranch        *b_genMetBarrel_pt;   //!
   TBranch        *b_genMetBarrel_phi;   //!
   TBranch        *b_L1CaloMetCentral_pt;   //!
   TBranch        *b_L1CaloMetCentral_phi;   //!
   TBranch        *b_L1CaloMetCentral_para;   //!
   TBranch        *b_L1CaloMetCentral_perp;   //!
   TBranch        *b_L1PFMetCentral_pt;   //!
   TBranch        *b_L1PFMetCentral_phi;   //!
   TBranch        *b_L1PFMetCentral_para;   //!
   TBranch        *b_L1PFMetCentral_perp;   //!
   TBranch        *b_L1PuppiMetCentral_pt;   //!
   TBranch        *b_L1PuppiMetCentral_phi;   //!
   TBranch        *b_L1PuppiMetCentral_para;   //!
   TBranch        *b_L1PuppiMetCentral_perp;   //!
   TBranch        *b_genMetCentral_pt;   //!
   TBranch        *b_genMetCentral_phi;   //!
   TBranch        *b_L1CaloMet_pt;   //!
   TBranch        *b_L1CaloMet_phi;   //!
   TBranch        *b_L1CaloMet_para;   //!
   TBranch        *b_L1CaloMet_perp;   //!
   TBranch        *b_L1PFMet_pt;   //!
   TBranch        *b_L1PFMet_phi;   //!
   TBranch        *b_L1PFMet_para;   //!
   TBranch        *b_L1PFMet_perp;   //!
   TBranch        *b_L1PuppiMet_pt;   //!
   TBranch        *b_L1PuppiMet_phi;   //!
   TBranch        *b_L1PuppiMet_para;   //!
   TBranch        *b_L1PuppiMet_perp;   //!
   TBranch        *b_genMet_pt;   //!
   TBranch        *b_genMet_phi;   //!
   TBranch        *b_nPFCandidate;   //!
   TBranch        *b_PFCandidate_eta;   //!
   TBranch        *b_PFCandidate_mass;   //!
   TBranch        *b_PFCandidate_phi;   //!
   TBranch        *b_PFCandidate_pt;   //!
   TBranch        *b_PFCandidate_vz;   //!
   TBranch        *b_PFCandidate_charge;   //!
   TBranch        *b_PFCandidate_pdgId;   //!
   TBranch        *b_nPFMu;   //!
   TBranch        *b_PFMu_eta;   //!
   TBranch        *b_PFMu_mass;   //!
   TBranch        *b_PFMu_phi;   //!
   TBranch        *b_PFMu_pt;   //!
   TBranch        *b_PFMu_vz;   //!
   TBranch        *b_PFMu_charge;   //!
   TBranch        *b_PFMu_quality;   //!

   upqt(TTree *tree=0);
   virtual ~upqt();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef upqt_cxx
upqt::upqt(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("./samples/perfNano_DY.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("./samples/perfNano_DY.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

upqt::~upqt()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t upqt::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t upqt::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void upqt::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("nGenJets", &nGenJets, &b_nGenJets);
   fChain->SetBranchAddress("GenJets_pt", GenJets_pt, &b_GenJets_pt);
   fChain->SetBranchAddress("GenJets_eta", GenJets_eta, &b_GenJets_eta);
   fChain->SetBranchAddress("GenJets_phi", GenJets_phi, &b_GenJets_phi);
   fChain->SetBranchAddress("GenJets_mass", GenJets_mass, &b_GenJets_mass);
   fChain->SetBranchAddress("nL1CaloJets", &nL1CaloJets, &b_nL1CaloJets);
   fChain->SetBranchAddress("L1CaloJets_pt", L1CaloJets_pt, &b_L1CaloJets_pt);
   fChain->SetBranchAddress("L1CaloJets_eta", L1CaloJets_eta, &b_L1CaloJets_eta);
   fChain->SetBranchAddress("L1CaloJets_phi", L1CaloJets_phi, &b_L1CaloJets_phi);
   fChain->SetBranchAddress("L1CaloJets_mass", L1CaloJets_mass, &b_L1CaloJets_mass);
   fChain->SetBranchAddress("L1CaloJets_genpt", L1CaloJets_genpt, &b_L1CaloJets_genpt);
   fChain->SetBranchAddress("L1CaloJets_gendr", L1CaloJets_gendr, &b_L1CaloJets_gendr);
   fChain->SetBranchAddress("nL1PFJets", &nL1PFJets, &b_nL1PFJets);
   fChain->SetBranchAddress("L1PFJets_pt", L1PFJets_pt, &b_L1PFJets_pt);
   fChain->SetBranchAddress("L1PFJets_eta", L1PFJets_eta, &b_L1PFJets_eta);
   fChain->SetBranchAddress("L1PFJets_phi", L1PFJets_phi, &b_L1PFJets_phi);
   fChain->SetBranchAddress("L1PFJets_mass", L1PFJets_mass, &b_L1PFJets_mass);
   fChain->SetBranchAddress("L1PFJets_genpt", L1PFJets_genpt, &b_L1PFJets_genpt);
   fChain->SetBranchAddress("L1PFJets_gendr", L1PFJets_gendr, &b_L1PFJets_gendr);
   fChain->SetBranchAddress("nL1PuppiJets", &nL1PuppiJets, &b_nL1PuppiJets);
   fChain->SetBranchAddress("L1PuppiJets_pt", L1PuppiJets_pt, &b_L1PuppiJets_pt);
   fChain->SetBranchAddress("L1PuppiJets_eta", L1PuppiJets_eta, &b_L1PuppiJets_eta);
   fChain->SetBranchAddress("L1PuppiJets_phi", L1PuppiJets_phi, &b_L1PuppiJets_phi);
   fChain->SetBranchAddress("L1PuppiJets_mass", L1PuppiJets_mass, &b_L1PuppiJets_mass);
   fChain->SetBranchAddress("L1PuppiJets_genpt", L1PuppiJets_genpt, &b_L1PuppiJets_genpt);
   fChain->SetBranchAddress("L1PuppiJets_gendr", L1PuppiJets_gendr, &b_L1PuppiJets_gendr);
   fChain->SetBranchAddress("L1CaloMetBarrel_pt", &L1CaloMetBarrel_pt, &b_L1CaloMetBarrel_pt);
   fChain->SetBranchAddress("L1CaloMetBarrel_phi", &L1CaloMetBarrel_phi, &b_L1CaloMetBarrel_phi);
   fChain->SetBranchAddress("L1CaloMetBarrel_para", &L1CaloMetBarrel_para, &b_L1CaloMetBarrel_para);
   fChain->SetBranchAddress("L1CaloMetBarrel_perp", &L1CaloMetBarrel_perp, &b_L1CaloMetBarrel_perp);
   fChain->SetBranchAddress("L1PFMetBarrel_pt", &L1PFMetBarrel_pt, &b_L1PFMetBarrel_pt);
   fChain->SetBranchAddress("L1PFMetBarrel_phi", &L1PFMetBarrel_phi, &b_L1PFMetBarrel_phi);
   fChain->SetBranchAddress("L1PFMetBarrel_para", &L1PFMetBarrel_para, &b_L1PFMetBarrel_para);
   fChain->SetBranchAddress("L1PFMetBarrel_perp", &L1PFMetBarrel_perp, &b_L1PFMetBarrel_perp);
   fChain->SetBranchAddress("L1PuppiMetBarrel_pt", &L1PuppiMetBarrel_pt, &b_L1PuppiMetBarrel_pt);
   fChain->SetBranchAddress("L1PuppiMetBarrel_phi", &L1PuppiMetBarrel_phi, &b_L1PuppiMetBarrel_phi);
   fChain->SetBranchAddress("L1PuppiMetBarrel_para", &L1PuppiMetBarrel_para, &b_L1PuppiMetBarrel_para);
   fChain->SetBranchAddress("L1PuppiMetBarrel_perp", &L1PuppiMetBarrel_perp, &b_L1PuppiMetBarrel_perp);
   fChain->SetBranchAddress("genMetBarrel_pt", &genMetBarrel_pt, &b_genMetBarrel_pt);
   fChain->SetBranchAddress("genMetBarrel_phi", &genMetBarrel_phi, &b_genMetBarrel_phi);
   fChain->SetBranchAddress("L1CaloMetCentral_pt", &L1CaloMetCentral_pt, &b_L1CaloMetCentral_pt);
   fChain->SetBranchAddress("L1CaloMetCentral_phi", &L1CaloMetCentral_phi, &b_L1CaloMetCentral_phi);
   fChain->SetBranchAddress("L1CaloMetCentral_para", &L1CaloMetCentral_para, &b_L1CaloMetCentral_para);
   fChain->SetBranchAddress("L1CaloMetCentral_perp", &L1CaloMetCentral_perp, &b_L1CaloMetCentral_perp);
   fChain->SetBranchAddress("L1PFMetCentral_pt", &L1PFMetCentral_pt, &b_L1PFMetCentral_pt);
   fChain->SetBranchAddress("L1PFMetCentral_phi", &L1PFMetCentral_phi, &b_L1PFMetCentral_phi);
   fChain->SetBranchAddress("L1PFMetCentral_para", &L1PFMetCentral_para, &b_L1PFMetCentral_para);
   fChain->SetBranchAddress("L1PFMetCentral_perp", &L1PFMetCentral_perp, &b_L1PFMetCentral_perp);
   fChain->SetBranchAddress("L1PuppiMetCentral_pt", &L1PuppiMetCentral_pt, &b_L1PuppiMetCentral_pt);
   fChain->SetBranchAddress("L1PuppiMetCentral_phi", &L1PuppiMetCentral_phi, &b_L1PuppiMetCentral_phi);
   fChain->SetBranchAddress("L1PuppiMetCentral_para", &L1PuppiMetCentral_para, &b_L1PuppiMetCentral_para);
   fChain->SetBranchAddress("L1PuppiMetCentral_perp", &L1PuppiMetCentral_perp, &b_L1PuppiMetCentral_perp);
   fChain->SetBranchAddress("genMetCentral_pt", &genMetCentral_pt, &b_genMetCentral_pt);
   fChain->SetBranchAddress("genMetCentral_phi", &genMetCentral_phi, &b_genMetCentral_phi);
   fChain->SetBranchAddress("L1CaloMet_pt", &L1CaloMet_pt, &b_L1CaloMet_pt);
   fChain->SetBranchAddress("L1CaloMet_phi", &L1CaloMet_phi, &b_L1CaloMet_phi);
   fChain->SetBranchAddress("L1CaloMet_para", &L1CaloMet_para, &b_L1CaloMet_para);
   fChain->SetBranchAddress("L1CaloMet_perp", &L1CaloMet_perp, &b_L1CaloMet_perp);
   fChain->SetBranchAddress("L1PFMet_pt", &L1PFMet_pt, &b_L1PFMet_pt);
   fChain->SetBranchAddress("L1PFMet_phi", &L1PFMet_phi, &b_L1PFMet_phi);
   fChain->SetBranchAddress("L1PFMet_para", &L1PFMet_para, &b_L1PFMet_para);
   fChain->SetBranchAddress("L1PFMet_perp", &L1PFMet_perp, &b_L1PFMet_perp);
   fChain->SetBranchAddress("L1PuppiMet_pt", &L1PuppiMet_pt, &b_L1PuppiMet_pt);
   fChain->SetBranchAddress("L1PuppiMet_phi", &L1PuppiMet_phi, &b_L1PuppiMet_phi);
   fChain->SetBranchAddress("L1PuppiMet_para", &L1PuppiMet_para, &b_L1PuppiMet_para);
   fChain->SetBranchAddress("L1PuppiMet_perp", &L1PuppiMet_perp, &b_L1PuppiMet_perp);
   fChain->SetBranchAddress("genMet_pt", &genMet_pt, &b_genMet_pt);
   fChain->SetBranchAddress("genMet_phi", &genMet_phi, &b_genMet_phi);
   fChain->SetBranchAddress("nPFCandidate", &nPFCandidate, &b_nPFCandidate);
   fChain->SetBranchAddress("PFCandidate_eta", PFCandidate_eta, &b_PFCandidate_eta);
   fChain->SetBranchAddress("PFCandidate_mass", PFCandidate_mass, &b_PFCandidate_mass);
   fChain->SetBranchAddress("PFCandidate_phi", PFCandidate_phi, &b_PFCandidate_phi);
   fChain->SetBranchAddress("PFCandidate_pt", PFCandidate_pt, &b_PFCandidate_pt);
   fChain->SetBranchAddress("PFCandidate_vz", PFCandidate_vz, &b_PFCandidate_vz);
   fChain->SetBranchAddress("PFCandidate_charge", PFCandidate_charge, &b_PFCandidate_charge);
   fChain->SetBranchAddress("PFCandidate_pdgId", PFCandidate_pdgId, &b_PFCandidate_pdgId);
   fChain->SetBranchAddress("nPFMu", &nPFMu, &b_nPFMu);
   fChain->SetBranchAddress("PFMu_eta", PFMu_eta, &b_PFMu_eta);
   fChain->SetBranchAddress("PFMu_mass", PFMu_mass, &b_PFMu_mass);
   fChain->SetBranchAddress("PFMu_phi", PFMu_phi, &b_PFMu_phi);
   fChain->SetBranchAddress("PFMu_pt", PFMu_pt, &b_PFMu_pt);
   fChain->SetBranchAddress("PFMu_vz", PFMu_vz, &b_PFMu_vz);
   fChain->SetBranchAddress("PFMu_charge", PFMu_charge, &b_PFMu_charge);
   fChain->SetBranchAddress("PFMu_quality", PFMu_quality, &b_PFMu_quality);
   Notify();
}

Bool_t upqt::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void upqt::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t upqt::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef upqt_cxx
