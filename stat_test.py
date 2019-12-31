from ROOT import *
from math import sqrt

rand=TRandom3(2020)
ntoys=100
f = TFile("out_stat_toy.root","recreate")

for mu in [5,100,1000,5000,10000]:
    # draw a toy poisson dataset and fit
    h = TH1F("h"+str(mu),"",100,0,2*mu)
    for i in range(ntoys): h.Fill(rand.Poisson(mu))
    h.Fit("gaus")
    h.Write()

f.Close()
