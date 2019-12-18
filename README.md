# MET_Response

After cloning this repository, you need to copy the samples in the path below
/afs/cern.ch/work/d/daekwon/public/metresp_samples


mkdir samples
scp (username)@lxplus7.cern.ch:/afs/cern.ch/work/d/daekwon/public/metresp_samples/*.root samples/

`run_upqt.sh` will run `upqt.C`. It will give `-<u_{||}>/<q_{T}>` response plot for DY sample.

`run_feat.sh` will run `feature_met.C`. It will give `<Reco MET>/<Gen MET>` response plot for DY sample.
