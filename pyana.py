#!/usr/bin/env python
from ROOT import *
from math import sqrt
from collections import OrderedDict
from array import array

f=TFile("samples/perfNano_DY.root")
t=f.Get("Events")

# book histograms
def book(h,name,n,a,b,title=""):
    h[name]=TH1F(name,title,n,a,b)
    h[name].Sumw2()
#def book2(h,name,xbins,ybins,title=""):
def book2(h,name,nx,ax,bx,ny,ay,by,title=""):
    h[name]=TH2F(name,title,nx,ax,bx,ny,ay,by)
    h[name].Sumw2()
def SgnPara(para,z):
    # return para modulus, with sign depending on (anti)-alignemnt
    #hists["dp1"].Fill( para.DeltaPhi(z) ) 
    return para.Mod()*(1. if abs(para.DeltaPhi(z))>TMath.Pi()/2 else -1.)
def SgnPerp(perp,z):
    # return perp modulus, with sign depending on relative angle
    #hists["dp2"].Fill( perp.DeltaPhi(z) ) 
    return perp.Mod()*(1. if perp.DeltaPhi(z)>0 else -1.)

hists=OrderedDict()
book(hists,"mz",80,0,160)
zpt_n=10
zpt_hi=200
book(hists,"ptz",2*zpt_n,0,zpt_hi)
book2(hists,"ptz_2d"    ,zpt_n,0,zpt_hi,8*zpt_n,0,zpt_hi)

para_n, para_lo, para_hi = (160,-300,500)
book2(hists,"pf_para"   ,zpt_n,0,zpt_hi,para_n,para_lo,para_hi)
book2(hists,"puppi_para",zpt_n,0,zpt_hi,para_n,para_lo,para_hi)
book2(hists,"gen_para"  ,zpt_n,0,zpt_hi,para_n,para_lo,para_hi)
perp_n, perp_lo, perp_hi = (160,-400,400)
book2(hists,"pf_perp"   ,zpt_n,0,zpt_hi,perp_n,perp_lo,perp_hi)
book2(hists,"puppi_perp",zpt_n,0,zpt_hi,perp_n,perp_lo,perp_hi)
book2(hists,"gen_perp"  ,zpt_n,0,zpt_hi,perp_n,perp_lo,perp_hi)

# helper objects
# met vectors
v_puppi=TVector2()
v_pf=TVector2()
v_gen=TVector2()
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
    
    # fill met vectors
    v_gen.SetMagPhi(e.genMetBarrel_pt,e.genMetBarrel_phi)
    v_pf.SetMagPhi(e.L1PFMet_pt,e.L1PFMet_phi)
    v_puppi.SetMagPhi(e.L1PuppiMet_pt,e.L1PuppiMet_phi)

    # MET=-(recoil+Z) so recoil = -(MET+Z)
    v_rec_gen   = -1.*(v_gen  +v_z)
    v_rec_pf    = -1.*(v_pf   +v_z)
    v_rec_puppi = -1.*(v_puppi+v_z)

    # calculate components
    v_para_gen   = v_rec_gen.Proj(v_z)
    v_perp_gen   = v_rec_gen.Norm(v_z)
    v_para_pf    = v_rec_pf.Proj(v_z)
    v_perp_pf    = v_rec_pf.Norm(v_z)
    v_para_puppi = v_rec_puppi.Proj(v_z)
    v_perp_puppi = v_rec_puppi.Norm(v_z)

    # record performance
    hists["ptz_2d"].Fill(v_z.Mod(), v_z.Mod() ) #silly
    hists["gen_para"].Fill(v_z.Mod(), SgnPara(v_para_gen,v_z))
    hists["gen_perp"].Fill(v_z.Mod(), SgnPerp(v_perp_gen,v_z))
    hists["pf_para"].Fill(v_z.Mod(), SgnPara(v_para_pf,v_z) )
    hists["pf_perp"].Fill(v_z.Mod(), SgnPerp(v_perp_pf,v_z) )
    hists["puppi_para"].Fill(v_z.Mod(), SgnPara(v_para_puppi,v_z) )
    hists["puppi_perp"].Fill(v_z.Mod(), SgnPerp(v_perp_puppi,v_z) )

    # if ei>10000: break

fout = TFile("histograms.root","recreate")
for n in hists:
    hists[n].Write()
fout.Close()

f.Close()
