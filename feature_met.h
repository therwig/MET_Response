//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Dec  3 19:46:00 2019 by ROOT version 6.14/04
// from TTree Events/Events
// found on file: perfNano_VBF_HToInvisible_PU200.v0.root
//////////////////////////////////////////////////////////

#ifndef feature_met_h
#define feature_met_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class feature_met {
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
   UInt_t          nL1CHSJets;
   Float_t         L1CHSJets_pt[164];   //[nL1CHSJets]
   Float_t         L1CHSJets_eta[164];   //[nL1CHSJets]
   Float_t         L1CHSJets_phi[164];   //[nL1CHSJets]
   Float_t         L1CHSJets_mass[164];   //[nL1CHSJets]
   Float_t         L1CHSJets_genpt[164];   //[nL1CHSJets]
   Float_t         L1CHSJets_gendr[164];   //[nL1CHSJets]
   UInt_t          nL1CaloJets;
   Float_t         L1CaloJets_pt[168];   //[nL1CaloJets]
   Float_t         L1CaloJets_eta[168];   //[nL1CaloJets]
   Float_t         L1CaloJets_phi[168];   //[nL1CaloJets]
   Float_t         L1CaloJets_mass[168];   //[nL1CaloJets]
   Float_t         L1CaloJets_genpt[168];   //[nL1CaloJets]
   Float_t         L1CaloJets_gendr[168];   //[nL1CaloJets]
   UInt_t          nL1PFJets;
   Float_t         L1PFJets_pt[173];   //[nL1PFJets]
   Float_t         L1PFJets_eta[173];   //[nL1PFJets]
   Float_t         L1PFJets_phi[173];   //[nL1PFJets]
   Float_t         L1PFJets_mass[173];   //[nL1PFJets]
   Float_t         L1PFJets_genpt[173];   //[nL1PFJets]
   Float_t         L1PFJets_gendr[173];   //[nL1PFJets]
   UInt_t          nL1PuppiJets;
   Float_t         L1PuppiJets_pt[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_eta[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_phi[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_mass[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_genpt[23];   //[nL1PuppiJets]
   Float_t         L1PuppiJets_gendr[23];   //[nL1PuppiJets]
   UInt_t          nL1TKJets;
   Float_t         L1TKJets_pt[54];   //[nL1TKJets]
   Float_t         L1TKJets_eta[54];   //[nL1TKJets]
   Float_t         L1TKJets_phi[54];   //[nL1TKJets]
   Float_t         L1TKJets_mass[54];   //[nL1TKJets]
   Float_t         L1TKJets_genpt[54];   //[nL1TKJets]
   Float_t         L1TKJets_gendr[54];   //[nL1TKJets]
   UInt_t          nL1TKV5Jets;
   Float_t         L1TKV5Jets_pt[15];   //[nL1TKV5Jets]
   Float_t         L1TKV5Jets_eta[15];   //[nL1TKV5Jets]
   Float_t         L1TKV5Jets_phi[15];   //[nL1TKV5Jets]
   Float_t         L1TKV5Jets_mass[15];   //[nL1TKV5Jets]
   Float_t         L1TKV5Jets_genpt[15];   //[nL1TKV5Jets]
   Float_t         L1TKV5Jets_gendr[15];   //[nL1TKV5Jets]
   UInt_t          nL1TKV6Jets;
   Float_t         L1TKV6Jets_pt[12];   //[nL1TKV6Jets]
   Float_t         L1TKV6Jets_eta[12];   //[nL1TKV6Jets]
   Float_t         L1TKV6Jets_phi[12];   //[nL1TKV6Jets]
   Float_t         L1TKV6Jets_mass[12];   //[nL1TKV6Jets]
   Float_t         L1TKV6Jets_genpt[12];   //[nL1TKV6Jets]
   Float_t         L1TKV6Jets_gendr[12];   //[nL1TKV6Jets]
   UInt_t          nL1TKVJets;
   Float_t         L1TKVJets_pt[19];   //[nL1TKVJets]
   Float_t         L1TKVJets_eta[19];   //[nL1TKVJets]
   Float_t         L1TKVJets_phi[19];   //[nL1TKVJets]
   Float_t         L1TKVJets_mass[19];   //[nL1TKVJets]
   Float_t         L1TKVJets_genpt[19];   //[nL1TKVJets]
   Float_t         L1TKVJets_gendr[19];   //[nL1TKVJets]
   Float_t         L1CHSMetBarrel_pt;
   Float_t         L1CHSMetBarrel_phi;
   Float_t         L1CHSMetBarrel_para;
   Float_t         L1CHSMetBarrel_perp;
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
   Float_t         L1TKMetBarrel_pt;
   Float_t         L1TKMetBarrel_phi;
   Float_t         L1TKMetBarrel_para;
   Float_t         L1TKMetBarrel_perp;
   Float_t         L1TKV5MetBarrel_pt;
   Float_t         L1TKV5MetBarrel_phi;
   Float_t         L1TKV5MetBarrel_para;
   Float_t         L1TKV5MetBarrel_perp;
   Float_t         L1TKV6MetBarrel_pt;
   Float_t         L1TKV6MetBarrel_phi;
   Float_t         L1TKV6MetBarrel_para;
   Float_t         L1TKV6MetBarrel_perp;
   Float_t         L1TKVMetBarrel_pt;
   Float_t         L1TKVMetBarrel_phi;
   Float_t         L1TKVMetBarrel_para;
   Float_t         L1TKVMetBarrel_perp;
   Float_t         genMetBarrel_pt;
   Float_t         genMetBarrel_phi;
   Float_t         L1CHSMetCentral_pt;
   Float_t         L1CHSMetCentral_phi;
   Float_t         L1CHSMetCentral_para;
   Float_t         L1CHSMetCentral_perp;
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
   Float_t         L1TKMetCentral_pt;
   Float_t         L1TKMetCentral_phi;
   Float_t         L1TKMetCentral_para;
   Float_t         L1TKMetCentral_perp;
   Float_t         L1TKV5MetCentral_pt;
   Float_t         L1TKV5MetCentral_phi;
   Float_t         L1TKV5MetCentral_para;
   Float_t         L1TKV5MetCentral_perp;
   Float_t         L1TKV6MetCentral_pt;
   Float_t         L1TKV6MetCentral_phi;
   Float_t         L1TKV6MetCentral_para;
   Float_t         L1TKV6MetCentral_perp;
   Float_t         L1TKVMetCentral_pt;
   Float_t         L1TKVMetCentral_phi;
   Float_t         L1TKVMetCentral_para;
   Float_t         L1TKVMetCentral_perp;
   Float_t         genMetCentral_pt;
   Float_t         genMetCentral_phi;
   Float_t         L1CHSMet_pt;
   Float_t         L1CHSMet_phi;
   Float_t         L1CHSMet_para;
   Float_t         L1CHSMet_perp;
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
   Float_t         L1TKMet_pt;
   Float_t         L1TKMet_phi;
   Float_t         L1TKMet_para;
   Float_t         L1TKMet_perp;
   Float_t         L1TKV5Met_pt;
   Float_t         L1TKV5Met_phi;
   Float_t         L1TKV5Met_para;
   Float_t         L1TKV5Met_perp;
   Float_t         L1TKV6Met_pt;
   Float_t         L1TKV6Met_phi;
   Float_t         L1TKV6Met_para;
   Float_t         L1TKV6Met_perp;
   Float_t         L1TKVMet_pt;
   Float_t         L1TKVMet_phi;
   Float_t         L1TKVMet_para;
   Float_t         L1TKVMet_perp;
   Float_t         genMet_pt;
   Float_t         genMet_phi;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_nGenJets;   //!
   TBranch        *b_GenJets_pt;   //!
   TBranch        *b_GenJets_eta;   //!
   TBranch        *b_GenJets_phi;   //!
   TBranch        *b_GenJets_mass;   //!
   TBranch        *b_nL1CHSJets;   //!
   TBranch        *b_L1CHSJets_pt;   //!
   TBranch        *b_L1CHSJets_eta;   //!
   TBranch        *b_L1CHSJets_phi;   //!
   TBranch        *b_L1CHSJets_mass;   //!
   TBranch        *b_L1CHSJets_genpt;   //!
   TBranch        *b_L1CHSJets_gendr;   //!
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
   TBranch        *b_nL1TKJets;   //!
   TBranch        *b_L1TKJets_pt;   //!
   TBranch        *b_L1TKJets_eta;   //!
   TBranch        *b_L1TKJets_phi;   //!
   TBranch        *b_L1TKJets_mass;   //!
   TBranch        *b_L1TKJets_genpt;   //!
   TBranch        *b_L1TKJets_gendr;   //!
   TBranch        *b_nL1TKV5Jets;   //!
   TBranch        *b_L1TKV5Jets_pt;   //!
   TBranch        *b_L1TKV5Jets_eta;   //!
   TBranch        *b_L1TKV5Jets_phi;   //!
   TBranch        *b_L1TKV5Jets_mass;   //!
   TBranch        *b_L1TKV5Jets_genpt;   //!
   TBranch        *b_L1TKV5Jets_gendr;   //!
   TBranch        *b_nL1TKV6Jets;   //!
   TBranch        *b_L1TKV6Jets_pt;   //!
   TBranch        *b_L1TKV6Jets_eta;   //!
   TBranch        *b_L1TKV6Jets_phi;   //!
   TBranch        *b_L1TKV6Jets_mass;   //!
   TBranch        *b_L1TKV6Jets_genpt;   //!
   TBranch        *b_L1TKV6Jets_gendr;   //!
   TBranch        *b_nL1TKVJets;   //!
   TBranch        *b_L1TKVJets_pt;   //!
   TBranch        *b_L1TKVJets_eta;   //!
   TBranch        *b_L1TKVJets_phi;   //!
   TBranch        *b_L1TKVJets_mass;   //!
   TBranch        *b_L1TKVJets_genpt;   //!
   TBranch        *b_L1TKVJets_gendr;   //!
   TBranch        *b_L1CHSMetBarrel_pt;   //!
   TBranch        *b_L1CHSMetBarrel_phi;   //!
   TBranch        *b_L1CHSMetBarrel_para;   //!
   TBranch        *b_L1CHSMetBarrel_perp;   //!
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
   TBranch        *b_L1TKMetBarrel_pt;   //!
   TBranch        *b_L1TKMetBarrel_phi;   //!
   TBranch        *b_L1TKMetBarrel_para;   //!
   TBranch        *b_L1TKMetBarrel_perp;   //!
   TBranch        *b_L1TKV5MetBarrel_pt;   //!
   TBranch        *b_L1TKV5MetBarrel_phi;   //!
   TBranch        *b_L1TKV5MetBarrel_para;   //!
   TBranch        *b_L1TKV5MetBarrel_perp;   //!
   TBranch        *b_L1TKV6MetBarrel_pt;   //!
   TBranch        *b_L1TKV6MetBarrel_phi;   //!
   TBranch        *b_L1TKV6MetBarrel_para;   //!
   TBranch        *b_L1TKV6MetBarrel_perp;   //!
   TBranch        *b_L1TKVMetBarrel_pt;   //!
   TBranch        *b_L1TKVMetBarrel_phi;   //!
   TBranch        *b_L1TKVMetBarrel_para;   //!
   TBranch        *b_L1TKVMetBarrel_perp;   //!
   TBranch        *b_genMetBarrel_pt;   //!
   TBranch        *b_genMetBarrel_phi;   //!
   TBranch        *b_L1CHSMetCentral_pt;   //!
   TBranch        *b_L1CHSMetCentral_phi;   //!
   TBranch        *b_L1CHSMetCentral_para;   //!
   TBranch        *b_L1CHSMetCentral_perp;   //!
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
   TBranch        *b_L1TKMetCentral_pt;   //!
   TBranch        *b_L1TKMetCentral_phi;   //!
   TBranch        *b_L1TKMetCentral_para;   //!
   TBranch        *b_L1TKMetCentral_perp;   //!
   TBranch        *b_L1TKV5MetCentral_pt;   //!
   TBranch        *b_L1TKV5MetCentral_phi;   //!
   TBranch        *b_L1TKV5MetCentral_para;   //!
   TBranch        *b_L1TKV5MetCentral_perp;   //!
   TBranch        *b_L1TKV6MetCentral_pt;   //!
   TBranch        *b_L1TKV6MetCentral_phi;   //!
   TBranch        *b_L1TKV6MetCentral_para;   //!
   TBranch        *b_L1TKV6MetCentral_perp;   //!
   TBranch        *b_L1TKVMetCentral_pt;   //!
   TBranch        *b_L1TKVMetCentral_phi;   //!
   TBranch        *b_L1TKVMetCentral_para;   //!
   TBranch        *b_L1TKVMetCentral_perp;   //!
   TBranch        *b_genMetCentral_pt;   //!
   TBranch        *b_genMetCentral_phi;   //!
   TBranch        *b_L1CHSMet_pt;   //!
   TBranch        *b_L1CHSMet_phi;   //!
   TBranch        *b_L1CHSMet_para;   //!
   TBranch        *b_L1CHSMet_perp;   //!
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
   TBranch        *b_L1TKMet_pt;   //!
   TBranch        *b_L1TKMet_phi;   //!
   TBranch        *b_L1TKMet_para;   //!
   TBranch        *b_L1TKMet_perp;   //!
   TBranch        *b_L1TKV5Met_pt;   //!
   TBranch        *b_L1TKV5Met_phi;   //!
   TBranch        *b_L1TKV5Met_para;   //!
   TBranch        *b_L1TKV5Met_perp;   //!
   TBranch        *b_L1TKV6Met_pt;   //!
   TBranch        *b_L1TKV6Met_phi;   //!
   TBranch        *b_L1TKV6Met_para;   //!
   TBranch        *b_L1TKV6Met_perp;   //!
   TBranch        *b_L1TKVMet_pt;   //!
   TBranch        *b_L1TKVMet_phi;   //!
   TBranch        *b_L1TKVMet_para;   //!
   TBranch        *b_L1TKVMet_perp;   //!
   TBranch        *b_genMet_pt;   //!
   TBranch        *b_genMet_phi;   //!

   feature_met(TTree *tree=0);
   virtual ~feature_met();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef feature_met_cxx
feature_met::feature_met(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("./samples/perfNano_VBF_HToInvisible_PU200.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("./samples/perfNano_VBF_HToInvisible_PU200.root");
      }
      f->GetObject("Events",tree);

   }
   Init(tree);
}

feature_met::~feature_met()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t feature_met::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t feature_met::LoadTree(Long64_t entry)
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

void feature_met::Init(TTree *tree)
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
   fChain->SetBranchAddress("nL1CHSJets", &nL1CHSJets, &b_nL1CHSJets);
   fChain->SetBranchAddress("L1CHSJets_pt", L1CHSJets_pt, &b_L1CHSJets_pt);
   fChain->SetBranchAddress("L1CHSJets_eta", L1CHSJets_eta, &b_L1CHSJets_eta);
   fChain->SetBranchAddress("L1CHSJets_phi", L1CHSJets_phi, &b_L1CHSJets_phi);
   fChain->SetBranchAddress("L1CHSJets_mass", L1CHSJets_mass, &b_L1CHSJets_mass);
   fChain->SetBranchAddress("L1CHSJets_genpt", L1CHSJets_genpt, &b_L1CHSJets_genpt);
   fChain->SetBranchAddress("L1CHSJets_gendr", L1CHSJets_gendr, &b_L1CHSJets_gendr);
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
   fChain->SetBranchAddress("nL1TKJets", &nL1TKJets, &b_nL1TKJets);
   fChain->SetBranchAddress("L1TKJets_pt", L1TKJets_pt, &b_L1TKJets_pt);
   fChain->SetBranchAddress("L1TKJets_eta", L1TKJets_eta, &b_L1TKJets_eta);
   fChain->SetBranchAddress("L1TKJets_phi", L1TKJets_phi, &b_L1TKJets_phi);
   fChain->SetBranchAddress("L1TKJets_mass", L1TKJets_mass, &b_L1TKJets_mass);
   fChain->SetBranchAddress("L1TKJets_genpt", L1TKJets_genpt, &b_L1TKJets_genpt);
   fChain->SetBranchAddress("L1TKJets_gendr", L1TKJets_gendr, &b_L1TKJets_gendr);
   fChain->SetBranchAddress("nL1TKV5Jets", &nL1TKV5Jets, &b_nL1TKV5Jets);
   fChain->SetBranchAddress("L1TKV5Jets_pt", L1TKV5Jets_pt, &b_L1TKV5Jets_pt);
   fChain->SetBranchAddress("L1TKV5Jets_eta", L1TKV5Jets_eta, &b_L1TKV5Jets_eta);
   fChain->SetBranchAddress("L1TKV5Jets_phi", L1TKV5Jets_phi, &b_L1TKV5Jets_phi);
   fChain->SetBranchAddress("L1TKV5Jets_mass", L1TKV5Jets_mass, &b_L1TKV5Jets_mass);
   fChain->SetBranchAddress("L1TKV5Jets_genpt", L1TKV5Jets_genpt, &b_L1TKV5Jets_genpt);
   fChain->SetBranchAddress("L1TKV5Jets_gendr", L1TKV5Jets_gendr, &b_L1TKV5Jets_gendr);
   fChain->SetBranchAddress("nL1TKV6Jets", &nL1TKV6Jets, &b_nL1TKV6Jets);
   fChain->SetBranchAddress("L1TKV6Jets_pt", L1TKV6Jets_pt, &b_L1TKV6Jets_pt);
   fChain->SetBranchAddress("L1TKV6Jets_eta", L1TKV6Jets_eta, &b_L1TKV6Jets_eta);
   fChain->SetBranchAddress("L1TKV6Jets_phi", L1TKV6Jets_phi, &b_L1TKV6Jets_phi);
   fChain->SetBranchAddress("L1TKV6Jets_mass", L1TKV6Jets_mass, &b_L1TKV6Jets_mass);
   fChain->SetBranchAddress("L1TKV6Jets_genpt", L1TKV6Jets_genpt, &b_L1TKV6Jets_genpt);
   fChain->SetBranchAddress("L1TKV6Jets_gendr", L1TKV6Jets_gendr, &b_L1TKV6Jets_gendr);
   fChain->SetBranchAddress("nL1TKVJets", &nL1TKVJets, &b_nL1TKVJets);
   fChain->SetBranchAddress("L1TKVJets_pt", L1TKVJets_pt, &b_L1TKVJets_pt);
   fChain->SetBranchAddress("L1TKVJets_eta", L1TKVJets_eta, &b_L1TKVJets_eta);
   fChain->SetBranchAddress("L1TKVJets_phi", L1TKVJets_phi, &b_L1TKVJets_phi);
   fChain->SetBranchAddress("L1TKVJets_mass", L1TKVJets_mass, &b_L1TKVJets_mass);
   fChain->SetBranchAddress("L1TKVJets_genpt", L1TKVJets_genpt, &b_L1TKVJets_genpt);
   fChain->SetBranchAddress("L1TKVJets_gendr", L1TKVJets_gendr, &b_L1TKVJets_gendr);
   fChain->SetBranchAddress("L1CHSMetBarrel_pt", &L1CHSMetBarrel_pt, &b_L1CHSMetBarrel_pt);
   fChain->SetBranchAddress("L1CHSMetBarrel_phi", &L1CHSMetBarrel_phi, &b_L1CHSMetBarrel_phi);
   fChain->SetBranchAddress("L1CHSMetBarrel_para", &L1CHSMetBarrel_para, &b_L1CHSMetBarrel_para);
   fChain->SetBranchAddress("L1CHSMetBarrel_perp", &L1CHSMetBarrel_perp, &b_L1CHSMetBarrel_perp);
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
   fChain->SetBranchAddress("L1TKMetBarrel_pt", &L1TKMetBarrel_pt, &b_L1TKMetBarrel_pt);
   fChain->SetBranchAddress("L1TKMetBarrel_phi", &L1TKMetBarrel_phi, &b_L1TKMetBarrel_phi);
   fChain->SetBranchAddress("L1TKMetBarrel_para", &L1TKMetBarrel_para, &b_L1TKMetBarrel_para);
   fChain->SetBranchAddress("L1TKMetBarrel_perp", &L1TKMetBarrel_perp, &b_L1TKMetBarrel_perp);
   fChain->SetBranchAddress("L1TKV5MetBarrel_pt", &L1TKV5MetBarrel_pt, &b_L1TKV5MetBarrel_pt);
   fChain->SetBranchAddress("L1TKV5MetBarrel_phi", &L1TKV5MetBarrel_phi, &b_L1TKV5MetBarrel_phi);
   fChain->SetBranchAddress("L1TKV5MetBarrel_para", &L1TKV5MetBarrel_para, &b_L1TKV5MetBarrel_para);
   fChain->SetBranchAddress("L1TKV5MetBarrel_perp", &L1TKV5MetBarrel_perp, &b_L1TKV5MetBarrel_perp);
   fChain->SetBranchAddress("L1TKV6MetBarrel_pt", &L1TKV6MetBarrel_pt, &b_L1TKV6MetBarrel_pt);
   fChain->SetBranchAddress("L1TKV6MetBarrel_phi", &L1TKV6MetBarrel_phi, &b_L1TKV6MetBarrel_phi);
   fChain->SetBranchAddress("L1TKV6MetBarrel_para", &L1TKV6MetBarrel_para, &b_L1TKV6MetBarrel_para);
   fChain->SetBranchAddress("L1TKV6MetBarrel_perp", &L1TKV6MetBarrel_perp, &b_L1TKV6MetBarrel_perp);
   fChain->SetBranchAddress("L1TKVMetBarrel_pt", &L1TKVMetBarrel_pt, &b_L1TKVMetBarrel_pt);
   fChain->SetBranchAddress("L1TKVMetBarrel_phi", &L1TKVMetBarrel_phi, &b_L1TKVMetBarrel_phi);
   fChain->SetBranchAddress("L1TKVMetBarrel_para", &L1TKVMetBarrel_para, &b_L1TKVMetBarrel_para);
   fChain->SetBranchAddress("L1TKVMetBarrel_perp", &L1TKVMetBarrel_perp, &b_L1TKVMetBarrel_perp);
   fChain->SetBranchAddress("genMetBarrel_pt", &genMetBarrel_pt, &b_genMetBarrel_pt);
   fChain->SetBranchAddress("genMetBarrel_phi", &genMetBarrel_phi, &b_genMetBarrel_phi);
   fChain->SetBranchAddress("L1CHSMetCentral_pt", &L1CHSMetCentral_pt, &b_L1CHSMetCentral_pt);
   fChain->SetBranchAddress("L1CHSMetCentral_phi", &L1CHSMetCentral_phi, &b_L1CHSMetCentral_phi);
   fChain->SetBranchAddress("L1CHSMetCentral_para", &L1CHSMetCentral_para, &b_L1CHSMetCentral_para);
   fChain->SetBranchAddress("L1CHSMetCentral_perp", &L1CHSMetCentral_perp, &b_L1CHSMetCentral_perp);
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
   fChain->SetBranchAddress("L1TKMetCentral_pt", &L1TKMetCentral_pt, &b_L1TKMetCentral_pt);
   fChain->SetBranchAddress("L1TKMetCentral_phi", &L1TKMetCentral_phi, &b_L1TKMetCentral_phi);
   fChain->SetBranchAddress("L1TKMetCentral_para", &L1TKMetCentral_para, &b_L1TKMetCentral_para);
   fChain->SetBranchAddress("L1TKMetCentral_perp", &L1TKMetCentral_perp, &b_L1TKMetCentral_perp);
   fChain->SetBranchAddress("L1TKV5MetCentral_pt", &L1TKV5MetCentral_pt, &b_L1TKV5MetCentral_pt);
   fChain->SetBranchAddress("L1TKV5MetCentral_phi", &L1TKV5MetCentral_phi, &b_L1TKV5MetCentral_phi);
   fChain->SetBranchAddress("L1TKV5MetCentral_para", &L1TKV5MetCentral_para, &b_L1TKV5MetCentral_para);
   fChain->SetBranchAddress("L1TKV5MetCentral_perp", &L1TKV5MetCentral_perp, &b_L1TKV5MetCentral_perp);
   fChain->SetBranchAddress("L1TKV6MetCentral_pt", &L1TKV6MetCentral_pt, &b_L1TKV6MetCentral_pt);
   fChain->SetBranchAddress("L1TKV6MetCentral_phi", &L1TKV6MetCentral_phi, &b_L1TKV6MetCentral_phi);
   fChain->SetBranchAddress("L1TKV6MetCentral_para", &L1TKV6MetCentral_para, &b_L1TKV6MetCentral_para);
   fChain->SetBranchAddress("L1TKV6MetCentral_perp", &L1TKV6MetCentral_perp, &b_L1TKV6MetCentral_perp);
   fChain->SetBranchAddress("L1TKVMetCentral_pt", &L1TKVMetCentral_pt, &b_L1TKVMetCentral_pt);
   fChain->SetBranchAddress("L1TKVMetCentral_phi", &L1TKVMetCentral_phi, &b_L1TKVMetCentral_phi);
   fChain->SetBranchAddress("L1TKVMetCentral_para", &L1TKVMetCentral_para, &b_L1TKVMetCentral_para);
   fChain->SetBranchAddress("L1TKVMetCentral_perp", &L1TKVMetCentral_perp, &b_L1TKVMetCentral_perp);
   fChain->SetBranchAddress("genMetCentral_pt", &genMetCentral_pt, &b_genMetCentral_pt);
   fChain->SetBranchAddress("genMetCentral_phi", &genMetCentral_phi, &b_genMetCentral_phi);
   fChain->SetBranchAddress("L1CHSMet_pt", &L1CHSMet_pt, &b_L1CHSMet_pt);
   fChain->SetBranchAddress("L1CHSMet_phi", &L1CHSMet_phi, &b_L1CHSMet_phi);
   fChain->SetBranchAddress("L1CHSMet_para", &L1CHSMet_para, &b_L1CHSMet_para);
   fChain->SetBranchAddress("L1CHSMet_perp", &L1CHSMet_perp, &b_L1CHSMet_perp);
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
   fChain->SetBranchAddress("L1TKMet_pt", &L1TKMet_pt, &b_L1TKMet_pt);
   fChain->SetBranchAddress("L1TKMet_phi", &L1TKMet_phi, &b_L1TKMet_phi);
   fChain->SetBranchAddress("L1TKMet_para", &L1TKMet_para, &b_L1TKMet_para);
   fChain->SetBranchAddress("L1TKMet_perp", &L1TKMet_perp, &b_L1TKMet_perp);
   fChain->SetBranchAddress("L1TKV5Met_pt", &L1TKV5Met_pt, &b_L1TKV5Met_pt);
   fChain->SetBranchAddress("L1TKV5Met_phi", &L1TKV5Met_phi, &b_L1TKV5Met_phi);
   fChain->SetBranchAddress("L1TKV5Met_para", &L1TKV5Met_para, &b_L1TKV5Met_para);
   fChain->SetBranchAddress("L1TKV5Met_perp", &L1TKV5Met_perp, &b_L1TKV5Met_perp);
   fChain->SetBranchAddress("L1TKV6Met_pt", &L1TKV6Met_pt, &b_L1TKV6Met_pt);
   fChain->SetBranchAddress("L1TKV6Met_phi", &L1TKV6Met_phi, &b_L1TKV6Met_phi);
   fChain->SetBranchAddress("L1TKV6Met_para", &L1TKV6Met_para, &b_L1TKV6Met_para);
   fChain->SetBranchAddress("L1TKV6Met_perp", &L1TKV6Met_perp, &b_L1TKV6Met_perp);
   fChain->SetBranchAddress("L1TKVMet_pt", &L1TKVMet_pt, &b_L1TKVMet_pt);
   fChain->SetBranchAddress("L1TKVMet_phi", &L1TKVMet_phi, &b_L1TKVMet_phi);
   fChain->SetBranchAddress("L1TKVMet_para", &L1TKVMet_para, &b_L1TKVMet_para);
   fChain->SetBranchAddress("L1TKVMet_perp", &L1TKVMet_perp, &b_L1TKVMet_perp);
   fChain->SetBranchAddress("genMet_pt", &genMet_pt, &b_genMet_pt);
   fChain->SetBranchAddress("genMet_phi", &genMet_phi, &b_genMet_phi);
   Notify();
}

Bool_t feature_met::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void feature_met::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t feature_met::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef feature_met_cxx
