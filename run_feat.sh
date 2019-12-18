#!/bin/bash -f

cp feature_met.C feature_met_tmp.C
cp feature_met.h feature_met_tmp.h

root -l -b << EOF
.L feature_met.C
feature_met a
a.Loop()
.q
EOF

sed 's/VBF/TTbar/' feature_met_tmp.C > feature_met.C
sed 's/perfNano_VBF_HToInvisible_PU200.root/perfNano_TTbar_PU200.root/' feature_met_tmp.h > feature_met.h
root -l -b << EOF
.L feature_met.C
feature_met a
a.Loop()
.q
EOF

sed 's/VBF/DY/' feature_met_tmp.C > feature_met.C
sed 's/perfNano_VBF_HToInvisible_PU200.root/perfNano_DY.root/' feature_met_tmp.h > feature_met.h
root -l -b << EOF
.L feature_met.C
feature_met a
a.Loop()
.q
EOF

cp feature_met_tmp.C feature_met.C
cp feature_met_tmp.h feature_met.h

rm feature_met_tmp.C
rm feature_met_tmp.h

