#!/usr/bin/env python
from ROOT import *
from math import sqrt
from collections import OrderedDict
from array import array

def GetHist(f,hists,name): 
    hists[name]=f.Get(name)

def FitSlices(h,fout=None,simple=True):
    name=h.GetName()
    nx=h.GetNbinsX()
    x     =[]
    xe    =[]
    mean  =[] 
    meane =[]
    width =[]
    widthe=[]
    for xi in range(1,nx+1):
        lo=h.GetXaxis().GetBinLowEdge(xi)
        hi=h.GetXaxis().GetBinUpEdge(xi)
        hslice=h.ProjectionY("{}_{}_{}".format(name,int(lo),int(hi)),xi,xi,"e")
        if hslice.GetEntries()<1: continue
        x.append((lo+hi)/2) 
        xe.append((hi-lo)/2)
        # fit
        if simple:
            mean.append(hslice.GetMean()) 
            meane.append(hslice.GetMean()/sqrt(hslice.GetEntries()))
            width.append(hslice.GetRMS())
            widthe.append(0.)
        else:
            fit_lo = hslice.GetBinLowEdge(1)
            fit_hi = hslice.GetBinLowEdge(1+hslice.GetNbinsX())
            func = TF1("func","gaus",fit_lo,fit_hi)
            fit_result = hslice.Fit(func,"QS","",fit_lo,fit_hi)
            mean.append(fit_result.Parameter(1)) 
            meane.append(fit_result.ParError(1)) 
            width.append(fit_result.Parameter(2))
            widthe.append(fit_result.ParError(2))
        if fout: 
            fout.cd()
            hslice.Write()
    gmean = TGraphErrors(len(x),array('f',x),array('f',mean),array('f',xe),array('f',meane))
    gwidth = TGraphErrors(len(x),array('f',x),array('f',width),array('f',xe),array('f',widthe))
    gmean.SetName("g_{}_mean".format(name))
    gwidth.SetName("g_{}_width".format(name))
    return gmean,gwidth
    #return (mean,meane,width,widthe)

def plot(g,ytitle="response",yrange=(0,1)):
    gStyle.SetOptStat(0)
    c = TCanvas("canv","",750,750)
    pad = TPad("pad", "pad", .005, .01, .995, .995)
    pad.Draw()
    pad.cd()

    gPad.SetLeftMargin(0.17)
    gPad.SetRightMargin(0.05)
    gPad.SetBottomMargin(0.1)
    gPad.SetTopMargin(0.05)

    #draw this guy first
    b = TH1D("b","",1,0,g.GetX()[g.GetN()-1]+g.GetEXhigh()[g.GetN()-1])
    b.Draw()
    
    b.GetXaxis().SetTitle("p_{T}(Z) [GeV]")
    b.GetXaxis().SetTitleOffset(1.2)
    b.GetYaxis().SetTitleOffset(1.5)
    b.GetYaxis().SetLabelSize(0.04)
    b.GetYaxis().SetTitleSize(0.04)
    b.GetYaxis().SetTitle(ytitle)
    b.GetYaxis().SetRangeUser(*yrange)
    b.Draw("axis")

    g.Draw("same")
    c.SaveAs("plots/{}.pdf".format(g.GetName()))

def RunAll(infile, res_file, fit_file, name, ):
    h = f_in.Get(name)
    yrange = (h.GetYaxis().GetBinLowEdge(1),h.GetYaxis().GetBinLowEdge(1+h.GetNbinsY()))
    gpair = FitSlices(h,f_fits)
    res_file.cd()
    plot(gpair[0],"response",yrange)
    plot(gpair[1],"resolution",(0,100) if ('abs' in name) else (0,1))

def ArrayDivideErrs(n,ne,d,de):
    x=[]
    xe=[]
    for i in range(len(n)):
        if d[i]==0 or n[i]==0:
            x +=[0.]
            xe+=[0.]
        else:
            x+=[n[i]/d[i]]
            xe+=[n[i]/d[i]*sqrt((ne[i]/n[i])**2+(de[i]/d[i])**2)]
    return x,xe

def RunFits(hz,hpara,hperp,name,fout=None,simple=True):
    #name=h.GetName()
    nx=hz.GetNbinsX()
    z     =[]
    ze    =[]
    zeup  =[]
    zedn  =[]
    para  =[] 
    parae =[]
    resPara =[]
    resParae=[]
    resPerp =[]
    resPerpe=[]

    for xi in range(1,nx+1):
        lo=hz.GetXaxis().GetBinLowEdge(xi)
        hi=hz.GetXaxis().GetBinUpEdge(xi)
        z_slice=hz.ProjectionY("{}_zpt_{}zpt{}".format(hz.GetName(),int(lo),int(hi)),xi,xi,"e")
        para_slice=hpara.ProjectionY("{}_para_{}zpt{}".format(hpara.GetName(),int(lo),int(hi)),xi,xi,"e")
        perp_slice=hperp.ProjectionY("{}_perp_{}zpt{}".format(hperp.GetName(),int(lo),int(hi)),xi,xi,"e")
        #if hslice.GetEntries()<1: continue
        # fit
        if simple:
            z.append(z_slice.GetMean())
            ze.append(z_slice.GetRMS())
            zeup.append(hi-z_slice.GetMean()) # asym errors
            zedn.append(z_slice.GetMean()-lo) # asym errors
            para.append(para_slice.GetMean())
            parae.append(para_slice.GetRMS()/sqrt(para_slice.GetEntries()) if para_slice.GetEntries() else 0.)
            resPara.append(para_slice.GetRMS())
            resPerp.append(perp_slice.GetRMS())
            resParae.append(0.)
            resPerpe.append(0.)
        # else:
        #     x.append((lo+hi)/2) 
        #     xe.append((hi-lo)/2)
        #     fit_lo = hslice.GetBinLowEdge(1)
        #     fit_hi = hslice.GetBinLowEdge(1+hslice.GetNbinsX())
        #     func = TF1("func","gaus",fit_lo,fit_hi)
        #     fit_result = hslice.Fit(func,"QS","",fit_lo,fit_hi)
        #     mean.append(fit_result.Parameter(1)) 
        #     meane.append(fit_result.ParError(1)) 
        #     width.append(fit_result.Parameter(2))
        #     widthe.append(fit_result.ParError(2))
        if fout: 
            fout.cd()
            para_slice.Write()
            perp_slice.Write()


    resp,respe = ArrayDivideErrs(para,parae,z,ze)

    g_resp = TGraphAsymmErrors(len(z),array('f',z),array('f',resp),
                               array('f',zedn), array('f',zeup),
                               array('f',respe),array('f',respe))
    g_resPara = TGraphAsymmErrors(len(z),array('f',z),array('f',resPara),
                                  array('f',zedn), array('f',zeup),
                                  array('f',resParae),array('f',resParae))
    g_resPerp = TGraphAsymmErrors(len(z),array('f',z),array('f',resPerp),
                                  array('f',zedn), array('f',zeup),
                                  array('f',resPerpe),array('f',resPerpe))
    g_resp.SetName("g_{}_resp".format(name))
    g_resPara.SetName("g_{}_para_res".format(name))
    g_resPerp.SetName("g_{}_perp_res".format(name))

    return g_resp,g_resPara,g_resPerp
            
    # gmean = TGraphErrors(len(x),array('f',x),array('f',mean),array('f',xe),array('f',meane))
    # gwidth = TGraphErrors(len(x),array('f',x),array('f',width),array('f',xe),array('f',widthe))
    # gmean.SetName("g_{}_mean".format(name))
    # gwidth.SetName("g_{}_width".format(name))
    # return gmean,gwidth
    #return (mean,meane,width,widthe)

def RunAll2(infile, res_file, fit_file, name, ):
    hz    = f_in.Get("ptz_2d")
    hpara = f_in.Get(name+"_para")
    hperp = f_in.Get(name+"_perp")
    gs = RunFits(hz,hpara,hperp,name,fout=fit_file)
    #g_resp,g_resPara,g_resPerp = RunFits(hz,hpara,hperp,fout=fit_file)
    res_file.cd()
    plot(gs[0],"response",(0,2))
    plot(gs[1],"para resolution",(0,200))
    plot(gs[2],"perp resolution",(0,200))


f_in = TFile("histograms.root","read")
f_out = TFile("results.root","recreate")
f_fits = TFile("fits.root","recreate")

# run analysis
RunAll2(f_in,f_out,f_fits,"pf")
RunAll2(f_in,f_out,f_fits,"puppi")
RunAll2(f_in,f_out,f_fits,"gen")

# book2(hists,"pf_para"   ,zpt_n,0,zpt_hi,para_n,para_lo,para_hi)
# book2(hists,"puppi_para",zpt_n,0,zpt_hi,para_n,para_lo,para_hi)
# book2(hists,"gen_para"  ,zpt_n,0,zpt_hi,para_n,para_lo,para_hi)

# RunAll(f_in,f_out,f_fits,"pf_abs"          )
# RunAll(f_in,f_out,f_fits,"pf_ratio"        )
# RunAll(f_in,f_out,f_fits,"puppi_abs"       )
# RunAll(f_in,f_out,f_fits,"puppi_ratio"     )
# RunAll(f_in,f_out,f_fits,"pf_para_abs"     )
# RunAll(f_in,f_out,f_fits,"pf_perp_abs"     )
# RunAll(f_in,f_out,f_fits,"pf_para_ratio"   )
# RunAll(f_in,f_out,f_fits,"pf_perp_ratio"   )
# RunAll(f_in,f_out,f_fits,"puppi_para_abs"  )
# RunAll(f_in,f_out,f_fits,"puppi_perp_abs"  )
# RunAll(f_in,f_out,f_fits,"puppi_para_ratio")
# RunAll(f_in,f_out,f_fits,"puppi_perp_ratio")

f_in.Close()
f_fits.Close()
f_out.Close()

exit(0)
#read histograms
f_in = TFile("histograms.root","read")
hists=OrderedDict()
GetHist(f_in,hists,"pf_abs"          )
GetHist(f_in,hists,"pf_ratio"        )
GetHist(f_in,hists,"puppi_abs"       )
GetHist(f_in,hists,"puppi_ratio"     )
GetHist(f_in,hists,"pf_para_abs"     ) #components
GetHist(f_in,hists,"pf_perp_abs"     )
GetHist(f_in,hists,"pf_para_ratio"   )
GetHist(f_in,hists,"pf_perp_ratio"   )
GetHist(f_in,hists,"puppi_para_abs"  )
GetHist(f_in,hists,"puppi_perp_abs"  )
GetHist(f_in,hists,"puppi_para_ratio")
GetHist(f_in,hists,"puppi_perp_ratio")

# figure out sensible histogram ranges
abs_range = (hists["pf_abs"].GetYaxis().GetBinLowEdge(1),hists["pf_abs"].GetYaxis().GetBinLowEdge(1+hists["pf_abs"].GetNbinsY()))
ratio_range = (hists["pf_ratio"].GetYaxis().GetBinLowEdge(1),hists["pf_ratio"].GetYaxis().GetBinLowEdge(1+hists["pf_ratio"].GetNbinsY()))
f_fits = TFile("fits.root","recreate")

gpairs=OrderedDict()
gpairs["puppi_ratio"] = FitSlices(hists["puppi_ratio"],f_fits)
gpairs["puppi_abs"] = FitSlices(hists["puppi_abs"],f_fits)

f_out = TFile("results.root","recreate")
for p in gpairs:
    gpairs[p][0].Write()
    gpairs[p][1].Write()
    plot(gpairs[p][0],"response",ratio_range)
    plot(gpairs[p][1],"resolution",abs_range)

f_in.Close()
f_fits.Close()
f_out.Close()


