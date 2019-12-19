#!/usr/bin/env python
from ROOT import *
from math import sqrt
from collections import OrderedDict

f=TFile("samples/perfNano_DY.root")
t=f.Get("Events")

# book histograms
def book(h,name,n,a,b,title=""):
    h[name]=TH1F(name,title,n,a,b)
#def book2(h,name,xbins,ybins,title=""):
def book2(h,name,nx,ax,bx,ny,ay,by,title=""):
    h[name]=TH2F(name,title,nx,ax,bx,ny,ay,by)

hists=OrderedDict()
book(hists,"mz",80,0,160)
zpt_n=20
zpt_hi=400
book(hists,"ptz",2*zpt_n,0,zpt_hi)
abs_n, abs_lo, abs_hi = (80,-100,300)
rel_n, rel_lo, rel_hi = (80,-1,4)
book2(hists,"pf_abs"          ,zpt_n,0,zpt_hi,abs_n,abs_lo,abs_hi)
book2(hists,"pf_para_abs"     ,zpt_n,0,zpt_hi,abs_n,abs_lo,abs_hi)
book2(hists,"pf_perp_abs"     ,zpt_n,0,zpt_hi,abs_n,abs_lo,abs_hi)
book2(hists,"pf_ratio"        ,zpt_n,0,zpt_hi,rel_n,rel_lo,rel_hi)
book2(hists,"pf_para_ratio"   ,zpt_n,0,zpt_hi,rel_n,rel_lo,rel_hi)
book2(hists,"pf_perp_ratio"   ,zpt_n,0,zpt_hi,rel_n,rel_lo,rel_hi)
book2(hists,"puppi_abs"       ,zpt_n,0,zpt_hi,abs_n,abs_lo,abs_hi)
book2(hists,"puppi_para_abs"  ,zpt_n,0,zpt_hi,abs_n,abs_lo,abs_hi)
book2(hists,"puppi_perp_abs"  ,zpt_n,0,zpt_hi,abs_n,abs_lo,abs_hi)
book2(hists,"puppi_ratio"     ,zpt_n,0,zpt_hi,rel_n,rel_lo,rel_hi)
book2(hists,"puppi_para_ratio",zpt_n,0,zpt_hi,rel_n,rel_lo,rel_hi)
book2(hists,"puppi_perp_ratio",zpt_n,0,zpt_hi,rel_n,rel_lo,rel_hi)

# helper objects
# met vectors
v_tmp=TVector2()
v_puppi=TVector2()
v_pf=TVector2()
v_pf_cands=TVector2()
v_gen=TVector2()
#components
v_para_pf =TVector2()
v_perp_pf = TVector2()
v_para_puppi = TVector2()
v_perp_puppi = TVector2()
#leptons
tlv1=TLorentzVector()
tlv2=TLorentzVector()
tlv_z=TLorentzVector()
v_z=TVector2()


for ei,e in enumerate(t):
    # require di-muon pair
    if e.nPFMu != 2: continue
    tlv1.SetPtEtaPhiM(e.PFMu_pt[0],e.PFMu_eta[0],e.PFMu_phi[0],0.1)
    tlv2.SetPtEtaPhiM(e.PFMu_pt[1],e.PFMu_eta[1],e.PFMu_phi[1],0.1)
    tlv_z = tlv1+tlv2
    v_z.SetMagPhi(tlv_z.Pt(), tlv_z.Phi())
    if abs(91.-tlv_z.M())>15.: continue
    hists["mz"].Fill(tlv_z.M())
    hists["ptz"].Fill(tlv_z.Pt())

    v_gen.SetMagPhi(e.genMetBarrel_pt,e.genMetBarrel_phi)
    v_pf.SetMagPhi(e.L1PFMet_pt,e.L1PFMet_phi)
    v_puppi.SetMagPhi(e.L1PuppiMet_pt,e.L1PuppiMet_phi)
    # subtract the Z component to isolate the recoil
    v_gen   -= v_z
    v_pf    -= v_z
    v_puppi -= v_z

    # met from all puppi cands, if desired
    if False:
        v_pf_cands.Set(0.,0.)
        for i in range(e.nPFCandidate):
            if abs(e.PFCandidate_pdgId[i])==13: continue
            v_tmp.SetMagPhi(e.PFCandidate_pt[i],e.PFCandidate_phi[i])
            v_pf_cands += v_tmp

    # calculate components
    v_para_pf = -1.*v_pf.Proj(v_gen)
    v_perp_pf = v_pf-v_para_pf
    v_para_puppi = -1.*v_puppi.Proj(v_gen)
    v_perp_puppi = v_puppi-v_para_puppi

    # record performance stats
    # pf
    hists["pf_abs"].  Fill(v_z.Mod(), v_pf.Mod()-v_gen.Mod() )
    hists["pf_ratio"].Fill(v_z.Mod(), v_pf.Mod()/v_gen.Mod() )
    hists["pf_para_abs"].  Fill(v_z.Mod(), v_para_pf.Mod()-v_gen.Mod() )
    hists["pf_para_ratio"].Fill(v_z.Mod(), v_para_pf.Mod()/v_gen.Mod() )
    hists["pf_perp_abs"].  Fill(v_z.Mod(), v_perp_pf.Mod() )
    hists["pf_perp_ratio"].Fill(v_z.Mod(), v_perp_pf.Mod()/v_gen.Mod() )
    # puppi
    hists["puppi_abs"].  Fill(v_z.Mod(), v_puppi.Mod()-v_gen.Mod() )
    hists["puppi_ratio"].Fill(v_z.Mod(), v_puppi.Mod()/v_gen.Mod() )
    hists["puppi_para_abs"].  Fill(v_z.Mod(), v_para_puppi.Mod()-v_gen.Mod() )
    hists["puppi_para_ratio"].Fill(v_z.Mod(), v_para_puppi.Mod()/v_gen.Mod() )
    hists["puppi_perp_abs"].  Fill(v_z.Mod(), v_perp_puppi.Mod() )
    hists["puppi_perp_ratio"].Fill(v_z.Mod(), v_perp_puppi.Mod()/v_gen.Mod() )

    if ei>10000: break

fout = TFile("histograms.root","recreate")
for n in hists:
    hists[n].Write()
fout.Close()

f.Close()
