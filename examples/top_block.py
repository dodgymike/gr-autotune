#!/usr/bin/env python2
##################################################
# GNU Radio Python Flow Graph
# Title: Top Block
# Generated: Wed Feb 24 15:07:57 2016
##################################################

if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from gnuradio import blocks
from gnuradio import eng_notation
from gnuradio import fft
from gnuradio import filter
from gnuradio import gr
from gnuradio import wxgui
from gnuradio.eng_option import eng_option
from gnuradio.fft import window
from gnuradio.filter import firdes
from gnuradio.wxgui import forms
from gnuradio.wxgui import scopesink2
from gnuradio.wxgui import waterfallsink2
from grc_gnuradio import wxgui as grc_wxgui
from optparse import OptionParser
import osmosdr
import time
import wx


class top_block(grc_wxgui.top_block_gui):

    def __init__(self):
        grc_wxgui.top_block_gui.__init__(self, title="Top Block")
        _icon_path = "/usr/share/icons/hicolor/32x32/apps/gnuradio-grc.png"
        self.SetIcon(wx.Icon(_icon_path, wx.BITMAP_TYPE_ANY))

        ##################################################
        # Variables
        ##################################################
        self.var_sample_rate = var_sample_rate = 2500000
        self.var_reverse_fft_size = var_reverse_fft_size = 32
        self.var_freq = var_freq = 433000000
        self.var_fft_size = var_fft_size = 2048

        ##################################################
        # Blocks
        ##################################################
        _var_sample_rate_sizer = wx.BoxSizer(wx.VERTICAL)
        self._var_sample_rate_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_var_sample_rate_sizer,
        	value=self.var_sample_rate,
        	callback=self.set_var_sample_rate,
        	label='var_sample_rate',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._var_sample_rate_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_var_sample_rate_sizer,
        	value=self.var_sample_rate,
        	callback=self.set_var_sample_rate,
        	minimum=1000000,
        	maximum=20000000,
        	num_steps=40,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_var_sample_rate_sizer)
        self._var_reverse_fft_size_text_box = forms.text_box(
        	parent=self.GetWin(),
        	value=self.var_reverse_fft_size,
        	callback=self.set_var_reverse_fft_size,
        	label='var_reverse_fft_size',
        	converter=forms.int_converter(),
        )
        self.Add(self._var_reverse_fft_size_text_box)
        self._var_freq_text_box = forms.text_box(
        	parent=self.GetWin(),
        	value=self.var_freq,
        	callback=self.set_var_freq,
        	label='var_freq',
        	converter=forms.float_converter(),
        )
        self.Add(self._var_freq_text_box)
        self._var_fft_size_text_box = forms.text_box(
        	parent=self.GetWin(),
        	value=self.var_fft_size,
        	callback=self.set_var_fft_size,
        	label='var_fft_size',
        	converter=forms.int_converter(),
        )
        self.Add(self._var_fft_size_text_box)
        self.notebook_0 = self.notebook_0 = wx.Notebook(self.GetWin(), style=wx.NB_RIGHT)
        self.notebook_0.AddPage(grc_wxgui.Panel(self.notebook_0), "Before filter")
        self.notebook_0.AddPage(grc_wxgui.Panel(self.notebook_0), "After filter")
        self.notebook_0.AddPage(grc_wxgui.Panel(self.notebook_0), "Post-FM")
        self.Add(self.notebook_0)
        self.wxgui_waterfallsink2_1_0_0 = waterfallsink2.waterfall_sink_c(
        	self.GetWin(),
        	baseband_freq=0,
        	dynamic_range=100,
        	ref_level=0,
        	ref_scale=2.0,
        	sample_rate=var_sample_rate*var_reverse_fft_size/var_fft_size,
        	fft_size=512,
        	fft_rate=15,
        	average=False,
        	avg_alpha=None,
        	title="From auto-tune",
        )
        self.Add(self.wxgui_waterfallsink2_1_0_0.win)
        self.wxgui_waterfallsink2_0 = waterfallsink2.waterfall_sink_c(
        	self.notebook_0.GetPage(0).GetWin(),
        	baseband_freq=var_freq,
        	dynamic_range=100,
        	ref_level=0,
        	ref_scale=2.0,
        	sample_rate=var_sample_rate,
        	fft_size=1024,
        	fft_rate=15,
        	average=False,
        	avg_alpha=None,
        	title="Waterfall Plot",
        	win=window.hanning,
        )
        self.notebook_0.GetPage(0).GridAdd(self.wxgui_waterfallsink2_0.win, 0, 0, 1, 1)
        self.wxgui_scopesink2_1_0 = scopesink2.scope_sink_f(
        	self.GetWin(),
        	title="After C2M2",
        	sample_rate=var_sample_rate*var_reverse_fft_size/var_fft_size,
        	v_scale=20,
        	v_offset=0,
        	t_scale=1,
        	ac_couple=True,
        	xy_mode=False,
        	num_inputs=1,
        	trig_mode=wxgui.TRIG_MODE_NORM,
        	y_axis_label="Amplitude",
        )
        self.Add(self.wxgui_scopesink2_1_0.win)
        self.osmosdr_source_0 = osmosdr.source( args="numchan=" + str(1) + " " + "hackrf=0" )
        self.osmosdr_source_0.set_sample_rate(var_sample_rate)
        self.osmosdr_source_0.set_center_freq(var_freq, 0)
        self.osmosdr_source_0.set_freq_corr(0, 0)
        self.osmosdr_source_0.set_dc_offset_mode(2, 0)
        self.osmosdr_source_0.set_iq_balance_mode(0, 0)
        self.osmosdr_source_0.set_gain_mode(False, 0)
        self.osmosdr_source_0.set_gain(10, 0)
        self.osmosdr_source_0.set_if_gain(20, 0)
        self.osmosdr_source_0.set_bb_gain(20, 0)
        self.osmosdr_source_0.set_antenna("", 0)
        self.osmosdr_source_0.set_bandwidth(0, 0)
          
        self.fft_vxx_1_0 = fft.fft_vcc(var_reverse_fft_size, False, (), True, 4)
        self.fft_vxx_0 = fft.fft_vcc(var_fft_size, True, (), False, 4)
        self.dc_blocker_xx_0 = filter.dc_blocker_cc(32, True)
        self.blocks_vector_to_stream_1_0 = blocks.vector_to_stream(gr.sizeof_gr_complex*1, var_reverse_fft_size)
        self.blocks_stream_to_vector_2 = blocks.stream_to_vector(gr.sizeof_gr_complex*1, var_reverse_fft_size)
        self.blocks_stream_to_vector_0 = blocks.stream_to_vector(gr.sizeof_gr_complex*1, var_fft_size)
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_gr_complex*1, "/home/mike/source/gr-autotune/examples/to-grc.fifo", False)
        self.blocks_file_sink_2 = blocks.file_sink(gr.sizeof_gr_complex*var_fft_size, "/home/mike/source/gr-autotune/examples/from-grc.fifo", True)
        self.blocks_file_sink_2.set_unbuffered(False)
        self.blocks_complex_to_mag_squared_0 = blocks.complex_to_mag_squared(1)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_complex_to_mag_squared_0, 0), (self.wxgui_scopesink2_1_0, 0))    
        self.connect((self.blocks_file_source_0, 0), (self.blocks_stream_to_vector_2, 0))    
        self.connect((self.blocks_stream_to_vector_0, 0), (self.fft_vxx_0, 0))    
        self.connect((self.blocks_stream_to_vector_2, 0), (self.fft_vxx_1_0, 0))    
        self.connect((self.blocks_vector_to_stream_1_0, 0), (self.blocks_complex_to_mag_squared_0, 0))    
        self.connect((self.blocks_vector_to_stream_1_0, 0), (self.wxgui_waterfallsink2_1_0_0, 0))    
        self.connect((self.dc_blocker_xx_0, 0), (self.blocks_stream_to_vector_0, 0))    
        self.connect((self.dc_blocker_xx_0, 0), (self.wxgui_waterfallsink2_0, 0))    
        self.connect((self.fft_vxx_0, 0), (self.blocks_file_sink_2, 0))    
        self.connect((self.fft_vxx_1_0, 0), (self.blocks_vector_to_stream_1_0, 0))    
        self.connect((self.osmosdr_source_0, 0), (self.dc_blocker_xx_0, 0))    


    def get_var_sample_rate(self):
        return self.var_sample_rate

    def set_var_sample_rate(self, var_sample_rate):
        self.var_sample_rate = var_sample_rate
        self._var_sample_rate_slider.set_value(self.var_sample_rate)
        self._var_sample_rate_text_box.set_value(self.var_sample_rate)
        self.osmosdr_source_0.set_sample_rate(self.var_sample_rate)
        self.wxgui_scopesink2_1_0.set_sample_rate(self.var_sample_rate*self.var_reverse_fft_size/self.var_fft_size)
        self.wxgui_waterfallsink2_0.set_sample_rate(self.var_sample_rate)
        self.wxgui_waterfallsink2_1_0_0.set_sample_rate(self.var_sample_rate*self.var_reverse_fft_size/self.var_fft_size)

    def get_var_reverse_fft_size(self):
        return self.var_reverse_fft_size

    def set_var_reverse_fft_size(self, var_reverse_fft_size):
        self.var_reverse_fft_size = var_reverse_fft_size
        self._var_reverse_fft_size_text_box.set_value(self.var_reverse_fft_size)
        self.wxgui_scopesink2_1_0.set_sample_rate(self.var_sample_rate*self.var_reverse_fft_size/self.var_fft_size)
        self.wxgui_waterfallsink2_1_0_0.set_sample_rate(self.var_sample_rate*self.var_reverse_fft_size/self.var_fft_size)

    def get_var_freq(self):
        return self.var_freq

    def set_var_freq(self, var_freq):
        self.var_freq = var_freq
        self._var_freq_text_box.set_value(self.var_freq)
        self.osmosdr_source_0.set_center_freq(self.var_freq, 0)
        self.wxgui_waterfallsink2_0.set_baseband_freq(self.var_freq)

    def get_var_fft_size(self):
        return self.var_fft_size

    def set_var_fft_size(self, var_fft_size):
        self.var_fft_size = var_fft_size
        self._var_fft_size_text_box.set_value(self.var_fft_size)
        self.wxgui_scopesink2_1_0.set_sample_rate(self.var_sample_rate*self.var_reverse_fft_size/self.var_fft_size)
        self.wxgui_waterfallsink2_1_0_0.set_sample_rate(self.var_sample_rate*self.var_reverse_fft_size/self.var_fft_size)


if __name__ == '__main__':
    parser = OptionParser(option_class=eng_option, usage="%prog: [options]")
    (options, args) = parser.parse_args()
    tb = top_block()
    tb.Start(True)
    tb.Wait()
