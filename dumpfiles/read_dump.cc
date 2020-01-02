#include "DiscretePFInputs.h"

void read_dump(){

    // the dump file output
    FILE *f = fopen("out.dump", "rb");

    // vector of PF objects to dump
    vector<l1tpf_int::PFParticle> pfs;

    uint64_t ie=0;
    while ( fread(&ie, sizeof(uint64_t), 1, f) ) {
        if (ie>15) break;

        pfs.clear();
        readManyFromFile(pfs,f);

        printf("Event %d has %d PF candidates \n", int(ie), int(pfs.size()));

        for(auto& pf : pfs){
            printf(" pt = %d, eta = %d, phi = %d, puppi wgt = %d, id = %d \n",
                   pf.hwPt,pf.hwEta,pf.hwPhi,pf.hwPuppiWeight,pf.hwId);
        }

    }
    fclose(f);
    gSystem->Exit(0);
}

