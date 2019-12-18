#!/bin/bash -f

root -l -b << EOF
.L upqt.C
upqt a
a.Loop()
.q
EOF

