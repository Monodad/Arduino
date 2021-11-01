<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="9" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="7" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="5" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="6" fill="9" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="led" urn="urn:adsk.eagle:library:259">
<description>&lt;b&gt;LEDs&lt;/b&gt;&lt;p&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;&lt;br&gt;
Extended by Federico Battaglin &lt;author&gt;&amp;lt;federico.rd@fdpinternational.com&amp;gt;&lt;/author&gt; with DUOLED</description>
<packages>
<package name="P47F-BOTTOM" urn="urn:adsk.eagle:footprint:15761/1" library_version="5">
<description>&lt;b&gt;PointLED® Enhanced Thinfilm LED&lt;/b&gt; BOTTOM mount&lt;p&gt;
Source: http://catalog.osram-os.com .. LA_LR_LS_LY_P47F_Pb_free.pdf</description>
<wire x1="-0.8" y1="-0.6095" x2="-1.7524" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="-1.7524" y1="-0.6095" x2="-1.7524" y2="-0.1714" width="0.1" layer="51"/>
<wire x1="-1.7524" y1="-0.1714" x2="-1.4953" y2="-0.1714" width="0.1" layer="51"/>
<wire x1="-1.4953" y1="-0.1714" x2="-1.4286" y2="-0.2286" width="0.1" layer="51"/>
<wire x1="-1.4286" y1="-0.2286" x2="-1.2667" y2="-0.2571" width="0.1" layer="51" curve="61.173957"/>
<wire x1="-1.2667" y1="-0.2571" x2="-1.2095" y2="-0.2" width="0.1" layer="51" curve="48.594558"/>
<wire x1="-1.2095" y1="-0.2" x2="-1.2381" y2="-0.0095" width="0.1" layer="51" curve="58.580846"/>
<wire x1="-1.2381" y1="-0.0095" x2="-1.2857" y2="0.0952" width="0.1" layer="51" curve="-26.758013"/>
<wire x1="-1.2857" y1="0.0952" x2="-1.2857" y2="0.2571" width="0.1" layer="51" curve="-22.142725"/>
<wire x1="-1.2857" y1="0.2571" x2="-1.1524" y2="0.6095" width="0.1" layer="51" curve="-19.309263"/>
<wire x1="-1.1524" y1="0.6095" x2="-0.9714" y2="0.6095" width="0.1" layer="51"/>
<wire x1="-0.9714" y1="0.6095" x2="-0.7524" y2="0.6095" width="0.1" layer="51"/>
<wire x1="-0.981" y1="-0.6" x2="-1.1143" y2="-0.3619" width="0.1" layer="51"/>
<wire x1="-1.1143" y1="-0.3619" x2="-0.9714" y2="-0.2952" width="0.1" layer="51"/>
<wire x1="-0.9334" y1="0.2667" x2="-1.1143" y2="0.3525" width="0.1" layer="51"/>
<wire x1="-1.1143" y1="0.3525" x2="-0.9714" y2="0.6095" width="0.1" layer="51"/>
<wire x1="-0.3048" y1="-0.0476" x2="-0.0857" y2="-0.2667" width="0.1" layer="52" curve="90"/>
<wire x1="-0.0857" y1="-0.2667" x2="0.2286" y2="-0.2667" width="0.1" layer="52"/>
<wire x1="0.2286" y1="-0.2667" x2="0.5429" y2="-0.2952" width="0.1" layer="52"/>
<wire x1="0.5429" y1="-0.2952" x2="0.6953" y2="-0.2381" width="0.1" layer="52" curve="51.565061"/>
<wire x1="0.6953" y1="-0.2381" x2="0.8" y2="0" width="0.1" layer="52" curve="39.925503"/>
<wire x1="-0.3048" y1="0.0476" x2="-0.3048" y2="-0.0476" width="0.1" layer="52"/>
<wire x1="-0.0857" y1="0.2667" x2="-0.3048" y2="0.0476" width="0.1" layer="52" curve="90"/>
<wire x1="-0.0857" y1="0.2666" x2="0.2286" y2="0.2666" width="0.1" layer="52"/>
<wire x1="0.5429" y1="0.2952" x2="0.2286" y2="0.2667" width="0.1" layer="52"/>
<wire x1="0.5429" y1="0.2952" x2="0.6953" y2="0.2381" width="0.1" layer="52" curve="-51.565061"/>
<wire x1="0.6953" y1="0.2381" x2="0.8" y2="0" width="0.1" layer="52" curve="-39.925503"/>
<wire x1="0.8" y1="0.6095" x2="1.7524" y2="0.6095" width="0.1" layer="51"/>
<wire x1="1.7524" y1="0.6095" x2="1.7524" y2="0.1714" width="0.1" layer="51"/>
<wire x1="1.7524" y1="0.1714" x2="1.4953" y2="0.1714" width="0.1" layer="51"/>
<wire x1="1.4953" y1="0.1714" x2="1.4286" y2="0.2286" width="0.1" layer="51"/>
<wire x1="1.4286" y1="0.2286" x2="1.2667" y2="0.2571" width="0.1" layer="51" curve="61.173957"/>
<wire x1="1.2667" y1="0.2571" x2="1.2095" y2="0.2" width="0.1" layer="51" curve="48.594558"/>
<wire x1="1.2095" y1="0.2" x2="1.2381" y2="0.0095" width="0.1" layer="51" curve="58.580846"/>
<wire x1="1.2381" y1="0.0095" x2="1.2857" y2="-0.0952" width="0.1" layer="51" curve="-26.758013"/>
<wire x1="1.2857" y1="-0.0952" x2="1.2857" y2="-0.2571" width="0.1" layer="51" curve="-22.142725"/>
<wire x1="1.2857" y1="-0.2571" x2="1.1524" y2="-0.6095" width="0.1" layer="51" curve="-19.309263"/>
<wire x1="1.1524" y1="-0.6095" x2="0.9714" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="0.9714" y1="-0.6095" x2="0.7524" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="0.981" y1="0.6" x2="1.1143" y2="0.3619" width="0.1" layer="51"/>
<wire x1="1.1143" y1="0.3619" x2="0.9714" y2="0.2952" width="0.1" layer="51"/>
<wire x1="0.9334" y1="-0.2667" x2="1.1143" y2="-0.3525" width="0.1" layer="51"/>
<wire x1="1.1143" y1="-0.3525" x2="0.9714" y2="-0.6095" width="0.1" layer="51"/>
<circle x="0" y="0" radius="0.9524" width="0.1" layer="22"/>
<smd name="A" x="-2.45" y="0" dx="2.6" dy="2.6" layer="1" stop="no" cream="no"/>
<smd name="C" x="2.45" y="0" dx="2.6" dy="2.6" layer="1" rot="R180" stop="no" cream="no"/>
<text x="-3.81" y="1.905" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-3.0066" y1="-0.1852" x2="-2.9972" y2="-0.1758" layer="16"/>
<rectangle x1="-1.825" y1="-0.9" x2="-1.15" y2="0.2" layer="29"/>
<rectangle x1="1.15" y1="-0.2" x2="1.825" y2="0.9" layer="29" rot="R180"/>
<rectangle x1="2.4937" y1="-0.0141" x2="2.5031" y2="-0.0047" layer="16" rot="R180"/>
<rectangle x1="-1.8" y1="-0.725" x2="-1.175" y2="0.05" layer="31"/>
<rectangle x1="1.175" y1="-0.05" x2="1.8" y2="0.725" layer="31" rot="R180"/>
<rectangle x1="-0.1" y1="-0.1" x2="0.1" y2="0.1" layer="52"/>
<hole x="0" y="0" drill="2.3"/>
</package>
<package name="P47F-TOP" urn="urn:adsk.eagle:footprint:15762/1" library_version="5">
<description>&lt;b&gt;PointLED® Enhanced Thinfilm LED&lt;/b&gt; TOP mount&lt;p&gt;
Source: http://catalog.osram-os.com .. LA_LR_LS_LY_P47F_Pb_free.pdf</description>
<wire x1="-0.8" y1="0.6095" x2="-1.7524" y2="0.6095" width="0.1" layer="51"/>
<wire x1="-1.7524" y1="0.6095" x2="-1.7524" y2="0.1714" width="0.1" layer="51"/>
<wire x1="-1.7524" y1="0.1714" x2="-1.4953" y2="0.1714" width="0.1" layer="51"/>
<wire x1="-1.4953" y1="0.1714" x2="-1.4286" y2="0.2286" width="0.1" layer="51"/>
<wire x1="-1.4286" y1="0.2286" x2="-1.2667" y2="0.2571" width="0.1" layer="51" curve="-61.21063"/>
<wire x1="-1.2667" y1="0.2571" x2="-1.2095" y2="0.2" width="0.1" layer="51" curve="-48.594558"/>
<wire x1="-1.2095" y1="0.2" x2="-1.2381" y2="0.0095" width="0.1" layer="51" curve="-58.580846"/>
<wire x1="-1.2381" y1="0.0095" x2="-1.2857" y2="-0.0952" width="0.1" layer="51" curve="26.758013"/>
<wire x1="-1.2857" y1="-0.0952" x2="-1.2857" y2="-0.2571" width="0.1" layer="51" curve="22.142725"/>
<wire x1="-1.2857" y1="-0.2571" x2="-1.1524" y2="-0.6095" width="0.1" layer="51" curve="19.307434"/>
<wire x1="-1.1524" y1="-0.6095" x2="-0.9714" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="-0.9714" y1="-0.6095" x2="-0.7524" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="-0.981" y1="0.6" x2="-1.1143" y2="0.3619" width="0.1" layer="51"/>
<wire x1="-1.1143" y1="0.3619" x2="-0.9714" y2="0.2952" width="0.1" layer="51"/>
<wire x1="-0.9334" y1="-0.2667" x2="-1.1143" y2="-0.3525" width="0.1" layer="51"/>
<wire x1="-1.1143" y1="-0.3525" x2="-0.9714" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="-0.3048" y1="0.0476" x2="-0.0857" y2="0.2667" width="0.1" layer="21" curve="-90"/>
<wire x1="-0.0857" y1="0.2667" x2="0.2286" y2="0.2667" width="0.1" layer="21"/>
<wire x1="0.2286" y1="0.2667" x2="0.5429" y2="0.2952" width="0.1" layer="21"/>
<wire x1="0.5429" y1="0.2952" x2="0.6953" y2="0.2381" width="0.1" layer="21" curve="-51.536625"/>
<wire x1="0.6953" y1="0.2381" x2="0.8" y2="0" width="0.1" layer="21" curve="-39.925503"/>
<wire x1="-0.3048" y1="-0.0476" x2="-0.3048" y2="0.0476" width="0.1" layer="21"/>
<wire x1="-0.0857" y1="-0.2667" x2="-0.3048" y2="-0.0476" width="0.1" layer="21" curve="-90"/>
<wire x1="-0.0857" y1="-0.2666" x2="0.2286" y2="-0.2666" width="0.1" layer="21"/>
<wire x1="0.5429" y1="-0.2952" x2="0.2286" y2="-0.2667" width="0.1" layer="21"/>
<wire x1="0.5429" y1="-0.2952" x2="0.6953" y2="-0.2381" width="0.1" layer="21" curve="51.536625"/>
<wire x1="0.6953" y1="-0.2381" x2="0.8" y2="0" width="0.1" layer="21" curve="39.925503"/>
<wire x1="0.8" y1="-0.6095" x2="1.7524" y2="-0.6095" width="0.1" layer="51"/>
<wire x1="1.7524" y1="-0.6095" x2="1.7524" y2="-0.1714" width="0.1" layer="51"/>
<wire x1="1.7524" y1="-0.1714" x2="1.4953" y2="-0.1714" width="0.1" layer="51"/>
<wire x1="1.4953" y1="-0.1714" x2="1.4286" y2="-0.2286" width="0.1" layer="51"/>
<wire x1="1.4286" y1="-0.2286" x2="1.2667" y2="-0.2571" width="0.1" layer="51" curve="-61.21063"/>
<wire x1="1.2667" y1="-0.2571" x2="1.2095" y2="-0.2" width="0.1" layer="51" curve="-48.594558"/>
<wire x1="1.2095" y1="-0.2" x2="1.2381" y2="-0.0095" width="0.1" layer="51" curve="-58.580846"/>
<wire x1="1.2381" y1="-0.0095" x2="1.2857" y2="0.0952" width="0.1" layer="51" curve="26.758013"/>
<wire x1="1.2857" y1="0.0952" x2="1.2857" y2="0.2571" width="0.1" layer="51" curve="22.142725"/>
<wire x1="1.2857" y1="0.2571" x2="1.1524" y2="0.6095" width="0.1" layer="51" curve="19.307434"/>
<wire x1="1.1524" y1="0.6095" x2="0.9714" y2="0.6095" width="0.1" layer="51"/>
<wire x1="0.9714" y1="0.6095" x2="0.7524" y2="0.6095" width="0.1" layer="51"/>
<wire x1="0.981" y1="-0.6" x2="1.1143" y2="-0.3619" width="0.1" layer="51"/>
<wire x1="1.1143" y1="-0.3619" x2="0.9714" y2="-0.2952" width="0.1" layer="51"/>
<wire x1="0.9334" y1="0.2667" x2="1.1143" y2="0.3525" width="0.1" layer="51"/>
<wire x1="1.1143" y1="0.3525" x2="0.9714" y2="0.6095" width="0.1" layer="51"/>
<circle x="0" y="0" radius="0.9524" width="0.1" layer="21"/>
<smd name="A" x="-2.45" y="0" dx="2.6" dy="2.6" layer="1" stop="no" cream="no"/>
<smd name="C" x="2.45" y="0" dx="2.6" dy="2.6" layer="1" rot="R180" stop="no" cream="no"/>
<text x="-3.81" y="1.905" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.81" y="-3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-3.0067" y1="0.1758" x2="-2.9972" y2="0.1853" layer="1"/>
<rectangle x1="-1.825" y1="-0.2" x2="-1.15" y2="0.9" layer="29"/>
<rectangle x1="1.15" y1="-0.9" x2="1.825" y2="0.2" layer="29" rot="R180"/>
<rectangle x1="2.4937" y1="0.0047" x2="2.5031" y2="0.0141" layer="1" rot="R180"/>
<rectangle x1="-1.8" y1="-0.05" x2="-1.175" y2="0.725" layer="31"/>
<rectangle x1="1.175" y1="-0.725" x2="1.8" y2="0.05" layer="31" rot="R180"/>
<rectangle x1="-0.1" y1="-0.1" x2="0.1" y2="0.1" layer="21"/>
<hole x="0" y="0" drill="2.3"/>
</package>
</packages>
<packages3d>
<package3d name="P47F-BOTTOM" urn="urn:adsk.eagle:package:15878/1" type="box" library_version="5">
<description>PointLED® Enhanced Thinfilm LED BOTTOM mount
Source: http://catalog.osram-os.com .. LA_LR_LS_LY_P47F_Pb_free.pdf</description>
<packageinstances>
<packageinstance name="P47F-BOTTOM"/>
</packageinstances>
</package3d>
<package3d name="P47F-TOP" urn="urn:adsk.eagle:package:15879/1" type="box" library_version="5">
<description>PointLED® Enhanced Thinfilm LED TOP mount
Source: http://catalog.osram-os.com .. LA_LR_LS_LY_P47F_Pb_free.pdf</description>
<packageinstances>
<packageinstance name="P47F-TOP"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="LED" urn="urn:adsk.eagle:symbol:15639/2" library_version="5">
<wire x1="1.27" y1="0" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="1.27" y1="-2.54" x2="0" y2="-2.54" width="0.254" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.27" y2="-2.54" width="0.254" layer="94"/>
<wire x1="1.27" y1="0" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="0" width="0.254" layer="94"/>
<wire x1="-2.032" y1="-0.762" x2="-3.429" y2="-2.159" width="0.1524" layer="94"/>
<wire x1="-1.905" y1="-1.905" x2="-3.302" y2="-3.302" width="0.1524" layer="94"/>
<text x="3.556" y="-4.572" size="1.778" layer="95" rot="R90">&gt;NAME</text>
<text x="5.715" y="-4.572" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="C" x="0" y="-5.08" visible="off" length="short" direction="pas" rot="R90"/>
<pin name="A" x="0" y="2.54" visible="off" length="short" direction="pas" rot="R270"/>
<polygon width="0.1524" layer="94">
<vertex x="-3.429" y="-2.159"/>
<vertex x="-3.048" y="-1.27"/>
<vertex x="-2.54" y="-1.778"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-3.302" y="-3.302"/>
<vertex x="-2.921" y="-2.413"/>
<vertex x="-2.413" y="-2.921"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="*P4" urn="urn:adsk.eagle:component:15960/3" prefix="LED" library_version="5">
<description>&lt;b&gt;PointLED® Enhanced Thinfilm LED&lt;/b&gt; TOP &amp; BOTTOM mount&lt;p&gt;
LS P47F, LR P47F, LA P47F, LY P47F, LT P4SG, LB P4SG, LW P4SG&lt;br&gt;
Source: http://catalog.osram-os.com .. LA_LR_LS_LY_P47F_Pb_free.pdf</description>
<gates>
<gate name="G$1" symbol="LED" x="0" y="0"/>
</gates>
<devices>
<device name="-BOTTOM" package="P47F-BOTTOM">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:15878/1"/>
</package3dinstances>
<technologies>
<technology name="LA">
<attribute name="POPULARITY" value="1" constant="no"/>
</technology>
<technology name="LB">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LR">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LS">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LT">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LW">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LY">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
<device name="-TOP" package="P47F-TOP">
<connects>
<connect gate="G$1" pin="A" pad="A"/>
<connect gate="G$1" pin="C" pad="C"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:15879/1"/>
</package3dinstances>
<technologies>
<technology name="LA">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LB">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LR">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LS">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LT">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LW">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
<technology name="LY">
<attribute name="POPULARITY" value="0" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="LED1" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED2" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED3" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED4" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED5" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED6" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED7" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED8" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED9" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED10" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED11" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED12" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED13" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED14" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED15" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED16" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED17" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED18" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED19" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED20" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED21" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED22" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED23" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED24" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED25" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED26" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED27" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED28" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED29" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED30" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED31" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED32" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED33" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED34" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
<part name="LED35" library="led" library_urn="urn:adsk.eagle:library:259" deviceset="*P4" device="-BOTTOM" package3d_urn="urn:adsk.eagle:package:15878/1" technology="LA"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="LED1" gate="G$1" x="20.32" y="59.69" smashed="yes">
<attribute name="NAME" x="23.876" y="55.118" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="26.035" y="55.118" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED2" gate="G$1" x="34.29" y="60.96" smashed="yes">
<attribute name="NAME" x="37.846" y="56.388" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="40.005" y="56.388" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED3" gate="G$1" x="52.07" y="60.96" smashed="yes">
<attribute name="NAME" x="55.626" y="56.388" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="57.785" y="56.388" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED4" gate="G$1" x="67.31" y="60.96" smashed="yes">
<attribute name="NAME" x="70.866" y="56.388" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="73.025" y="56.388" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED5" gate="G$1" x="72.39" y="41.91" smashed="yes">
<attribute name="NAME" x="75.946" y="37.338" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="78.105" y="37.338" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED6" gate="G$1" x="34.29" y="31.75" smashed="yes">
<attribute name="NAME" x="37.846" y="27.178" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="40.005" y="27.178" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED7" gate="G$1" x="19.05" y="30.48" smashed="yes">
<attribute name="NAME" x="22.606" y="25.908" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="24.765" y="25.908" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED8" gate="G$1" x="1.27" y="29.21" smashed="yes">
<attribute name="NAME" x="4.826" y="24.638" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="6.985" y="24.638" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED9" gate="G$1" x="6.35" y="13.97" smashed="yes">
<attribute name="NAME" x="9.906" y="9.398" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="12.065" y="9.398" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED10" gate="G$1" x="40.64" y="8.89" smashed="yes">
<attribute name="NAME" x="44.196" y="4.318" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="46.355" y="4.318" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED11" gate="G$1" x="64.77" y="12.7" smashed="yes">
<attribute name="NAME" x="68.326" y="8.128" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="70.485" y="8.128" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED12" gate="G$1" x="64.77" y="27.94" smashed="yes">
<attribute name="NAME" x="68.326" y="23.368" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="70.485" y="23.368" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED13" gate="G$1" x="96.52" y="17.78" smashed="yes">
<attribute name="NAME" x="100.076" y="13.208" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="102.235" y="13.208" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED14" gate="G$1" x="102.87" y="49.53" smashed="yes">
<attribute name="NAME" x="106.426" y="44.958" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="108.585" y="44.958" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED15" gate="G$1" x="93.98" y="71.12" smashed="yes">
<attribute name="NAME" x="97.536" y="66.548" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="99.695" y="66.548" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED16" gate="G$1" x="78.74" y="83.82" smashed="yes">
<attribute name="NAME" x="82.296" y="79.248" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="84.455" y="79.248" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED17" gate="G$1" x="39.37" y="87.63" smashed="yes">
<attribute name="NAME" x="42.926" y="83.058" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="45.085" y="83.058" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED18" gate="G$1" x="15.24" y="77.47" smashed="yes">
<attribute name="NAME" x="18.796" y="72.898" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="20.955" y="72.898" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED19" gate="G$1" x="-11.43" y="52.07" smashed="yes">
<attribute name="NAME" x="-7.874" y="47.498" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-5.715" y="47.498" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED20" gate="G$1" x="-12.7" y="78.74" smashed="yes">
<attribute name="NAME" x="-9.144" y="74.168" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-6.985" y="74.168" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED21" gate="G$1" x="1.27" y="90.17" smashed="yes">
<attribute name="NAME" x="4.826" y="85.598" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="6.985" y="85.598" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED22" gate="G$1" x="-12.7" y="101.6" smashed="yes">
<attribute name="NAME" x="-9.144" y="97.028" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-6.985" y="97.028" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED23" gate="G$1" x="-20.32" y="82.55" smashed="yes">
<attribute name="NAME" x="-16.764" y="77.978" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-14.605" y="77.978" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED24" gate="G$1" x="20.32" y="48.26" smashed="yes">
<attribute name="NAME" x="23.876" y="43.688" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="26.035" y="43.688" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED25" gate="G$1" x="2.54" y="24.13" smashed="yes">
<attribute name="NAME" x="6.096" y="19.558" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="8.255" y="19.558" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED26" gate="G$1" x="-13.97" y="15.24" smashed="yes">
<attribute name="NAME" x="-10.414" y="10.668" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-8.255" y="10.668" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED27" gate="G$1" x="12.7" y="62.23" smashed="yes">
<attribute name="NAME" x="16.256" y="57.658" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="18.415" y="57.658" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED28" gate="G$1" x="-16.51" y="76.2" smashed="yes">
<attribute name="NAME" x="-12.954" y="71.628" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-10.795" y="71.628" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED29" gate="G$1" x="-5.08" y="40.64" smashed="yes">
<attribute name="NAME" x="-1.524" y="36.068" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="0.635" y="36.068" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED30" gate="G$1" x="-26.67" y="33.02" smashed="yes">
<attribute name="NAME" x="-23.114" y="28.448" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-20.955" y="28.448" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED31" gate="G$1" x="-3.81" y="67.31" smashed="yes">
<attribute name="NAME" x="-0.254" y="62.738" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="1.905" y="62.738" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED32" gate="G$1" x="-19.05" y="72.39" smashed="yes">
<attribute name="NAME" x="-15.494" y="67.818" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="-13.335" y="67.818" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED33" gate="G$1" x="29.21" y="35.56" smashed="yes">
<attribute name="NAME" x="32.766" y="30.988" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="34.925" y="30.988" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED34" gate="G$1" x="60.96" y="31.75" smashed="yes">
<attribute name="NAME" x="64.516" y="27.178" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="66.675" y="27.178" size="1.778" layer="96" rot="R90"/>
</instance>
<instance part="LED35" gate="G$1" x="33.02" y="11.43" smashed="yes">
<attribute name="NAME" x="36.576" y="6.858" size="1.778" layer="95" rot="R90"/>
<attribute name="VALUE" x="38.735" y="6.858" size="1.778" layer="96" rot="R90"/>
</instance>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
