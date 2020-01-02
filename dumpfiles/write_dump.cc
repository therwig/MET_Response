#include "DiscretePFInputs.h"


void write_dump(){

    // read inputs from the ttree
    TFile* fin = new TFile("../samples/perfNano_DY.root","read");
    TTree* t = (TTree*) fin->Get("Events");
    TTreeReader reader(t);
    // read pf objects
    TTreeReaderValue<uint>  nPFCandidate(reader, "nPFCandidate");
    TTreeReaderArray<float> PFCandidate_pt(reader, "PFCandidate_pt");
    TTreeReaderArray<float> PFCandidate_eta(reader, "PFCandidate_eta");
    TTreeReaderArray<float> PFCandidate_phi(reader, "PFCandidate_phi");
    TTreeReaderArray<float> PFCandidate_m(reader, "PFCandidate_mass");
    TTreeReaderArray<float> PFCandidate_vz(reader, "PFCandidate_vz");
    TTreeReaderArray<int>   PFCandidate_charge(reader, "PFCandidate_charge");
    TTreeReaderArray<int>   PFCandidate_pdgId(reader, "PFCandidate_pdgId");

    // the dump file output
    FILE *f = fopen("out.dump", "wb");
    // vector of PF objects to dump
    vector<l1tpf_int::PFParticle> pfs;

    uint64_t ie=0;
    while (reader.Next()) {
        if (ie>10) break;
        
        cout << *nPFCandidate << endl;

        pfs.clear();
        pfs.resize(*nPFCandidate);
        for(uint ip=0;ip<*nPFCandidate;ip++){
            pfs[ip].hwPt  = PFCandidate_pt[ip] * l1tpf_int::CaloCluster::PT_SCALE; // int16 (in 1/4 GeV)
            pfs[ip].hwEta = PFCandidate_eta[ip] * l1tpf_int::CaloCluster::ETAPHI_SCALE; // int16
            pfs[ip].hwPhi = PFCandidate_phi[ip] * l1tpf_int::CaloCluster::ETAPHI_SCALE; // int16
            pfs[ip].hwPuppiWeight = 1.0 *  l1tpf_int::PFParticle::PUPPI_SCALE; // int8
            switch (abs(PFCandidate_pdgId[ip])) { // check pdgID to record (int8)
            case 11: // electron -> id = 1
                pfs[ip].hwId=1;
                break;
            case 13: // muon -> id = 4
                pfs[ip].hwId=4;
                break;
            case 22: // photon -> id = 3
                pfs[ip].hwId=3;
                break;
            default: // hadron -> neutral id = 2 / charged id = 0
                pfs[ip].hwId = PFCandidate_charge[ip] ? 0 : 2;
            }
        }
        //write event number and pf cands
        fwrite(&ie, sizeof(uint64_t), 1, f);
        writeManyToFile(pfs,f);

        ie++;
    }
    fin->Close();
    fclose(f);
    gSystem->Exit(0);
}

