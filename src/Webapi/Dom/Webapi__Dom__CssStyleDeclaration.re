type t = Dom.cssStyleDeclaration;
type cssRule; /* TODO: Move to Webapi__Dom */

[@mel.get] external cssText: t => string = "cssText";
[@mel.set] external setCssText: (t, string) => unit = "cssText";
[@mel.get] external length: t => int = "length";
[@mel.get] external parentRule: t => cssRule = "parentRule";

[@mel.send]
external getPropertyPriority: (string, [@mel.this] t) => string =
  "getPropertyPriority";
[@mel.send]
external getPropertyValue: (string, [@mel.this] t) => string =
  "getPropertyValue";
[@mel.send] external item: (int, [@mel.this] t) => string = "item";
[@mel.send]
external removeProperty: (string, [@mel.this] t) => string = "removeProperty";
[@mel.send]
external setProperty: (string, string, string, [@mel.this] t) => unit =
  "setProperty" /* [@mel.send] external setPropertyValue : (string, string) => ([@mel.this] t) => unit = "setPropertyValue";*/; /* not mentioned by MDN and not implemented by chrome, but in the CSSOM spec:  https://drafts.csswg.org/cssom/#the-cssstyledeclaration-interface */

/* CSS2Properties */

[@mel.get] external azimuth: t => string = "azimuth";
[@mel.get] external background: t => string = "background";
[@mel.get] external backgroundAttachment: t => string = "backgroundAttachment";
[@mel.get] external backgroundColor: t => string = "backgroundColor";
[@mel.get] external backgroundImage: t => string = "backgroundImage";
[@mel.get] external backgroundPosition: t => string = "backgroundPosition";
[@mel.get] external backgroundRepeat: t => string = "backgroundRepeat";
[@mel.get] external border: t => string = "border";
[@mel.get] external borderCollapse: t => string = "borderCollapse";
[@mel.get] external borderColor: t => string = "borderColor";
[@mel.get] external borderSpacing: t => string = "borderSpacing";
[@mel.get] external borderStyle: t => string = "borderStyle";
[@mel.get] external borderTop: t => string = "borderTop";
[@mel.get] external borderRight: t => string = "borderRight";
[@mel.get] external borderBottom: t => string = "borderBottom";
[@mel.get] external borderLeft: t => string = "borderLeft";
[@mel.get] external borderTopColor: t => string = "borderTopColor";
[@mel.get] external borderRightColor: t => string = "borderRightColor";
[@mel.get] external borderBottomColor: t => string = "borderBottomColor";
[@mel.get] external borderLeftColor: t => string = "borderLeftColor";
[@mel.get] external borderTopStyle: t => string = "borderTopStyle";
[@mel.get] external borderRightStyle: t => string = "borderRightStyle";
[@mel.get] external borderBottomStyle: t => string = "borderBottomStyle";
[@mel.get] external borderLeftStyle: t => string = "borderLeftStyle";
[@mel.get] external borderTopWidth: t => string = "borderTopWidth";
[@mel.get] external borderRightWidth: t => string = "borderRightWidth";
[@mel.get] external borderBottomWidth: t => string = "borderBottomWidth";
[@mel.get] external borderLeftWidth: t => string = "borderLeftWidth";
[@mel.get] external borderWidth: t => string = "borderWidth";
[@mel.get] external bottom: t => string = "bottom";
[@mel.get] external captionSide: t => string = "captionSide";
[@mel.get] external clear: t => string = "clear";
[@mel.get] external clip: t => string = "clip";
[@mel.get] external color: t => string = "color";
[@mel.get] external content: t => string = "content";
[@mel.get] external counterIncrement: t => string = "counterIncrement";
[@mel.get] external counterReset: t => string = "counterReset";
[@mel.get] external cue: t => string = "cue";
[@mel.get] external cueAfter: t => string = "cueAfter";
[@mel.get] external cueBefore: t => string = "cueBefore";
[@mel.get] external cursor: t => string = "cursor";
[@mel.get] external direction: t => string = "direction";
[@mel.get] external display: t => string = "display";
[@mel.get] external elevation: t => string = "elevation";
[@mel.get] external emptyCells: t => string = "emptyCells";
[@mel.get] external cssFloat: t => string = "cssFloat";
[@mel.get] external font: t => string = "font";
[@mel.get] external fontFamily: t => string = "fontFamily";
[@mel.get] external fontSize: t => string = "fontSize";
[@mel.get] external fontSizeAdjust: t => string = "fontSizeAdjust";
[@mel.get] external fontStretch: t => string = "fontStretch";
[@mel.get] external fontStyle: t => string = "fontStyle";
[@mel.get] external fontVariant: t => string = "fontVariant";
[@mel.get] external fontWeight: t => string = "fontWeight";
[@mel.get] external height: t => string = "height";
[@mel.get] external left: t => string = "left";
[@mel.get] external letterSpacing: t => string = "letterSpacing";
[@mel.get] external lineHeight: t => string = "lineHeight";
[@mel.get] external listStyle: t => string = "listStyle";
[@mel.get] external listStyleImage: t => string = "listStyleImage";
[@mel.get] external listStylePosition: t => string = "listStylePosition";
[@mel.get] external listStyleType: t => string = "listStyleType";
[@mel.get] external margin: t => string = "margin";
[@mel.get] external marginTop: t => string = "marginTop";
[@mel.get] external marginRight: t => string = "marginRight";
[@mel.get] external marginBottom: t => string = "marginBottom";
[@mel.get] external marginLeft: t => string = "marginLeft";
[@mel.get] external markerOffset: t => string = "markerOffset";
[@mel.get] external marks: t => string = "marks";
[@mel.get] external maxHeight: t => string = "maxHeight";
[@mel.get] external maxWidth: t => string = "maxWidth";
[@mel.get] external minHeight: t => string = "minHeight";
[@mel.get] external minWidth: t => string = "minWidth";
[@mel.get] external orphans: t => string = "orphans";
[@mel.get] external outline: t => string = "outline";
[@mel.get] external outlineColor: t => string = "outlineColor";
[@mel.get] external outlineStyle: t => string = "outlineStyle";
[@mel.get] external outlineWidth: t => string = "outlineWidth";
[@mel.get] external overflow: t => string = "overflow";
[@mel.get] external padding: t => string = "padding";
[@mel.get] external paddingTop: t => string = "paddingTop";
[@mel.get] external paddingRight: t => string = "paddingRight";
[@mel.get] external paddingBottom: t => string = "paddingBottom";
[@mel.get] external paddingLeft: t => string = "paddingLeft";
[@mel.get] external page: t => string = "page";
[@mel.get] external pageBreakAfter: t => string = "pageBreakAfter";
[@mel.get] external pageBreakBefore: t => string = "pageBreakBefore";
[@mel.get] external pageBreakInside: t => string = "pageBreakInside";
[@mel.get] external pause: t => string = "pause";
[@mel.get] external pauseAfter: t => string = "pauseAfter";
[@mel.get] external pauseBefore: t => string = "pauseBefore";
[@mel.get] external pitch: t => string = "pitch";
[@mel.get] external pitchRange: t => string = "pitchRange";
[@mel.get] external playDuring: t => string = "playDuring";
[@mel.get] external position: t => string = "position";
[@mel.get] external quotes: t => string = "quotes";
[@mel.get] external richness: t => string = "richness";
[@mel.get] external right: t => string = "right";
[@mel.get] external size: t => string = "size";
[@mel.get] external speak: t => string = "speak";
[@mel.get] external speakHeader: t => string = "speakHeader";
[@mel.get] external speakNumeral: t => string = "speakNumeral";
[@mel.get] external speakPunctuation: t => string = "speakPunctuation";
[@mel.get] external speechRate: t => string = "speechRate";
[@mel.get] external stress: t => string = "stress";
[@mel.get] external tableLayout: t => string = "tableLayout";
[@mel.get] external textAlign: t => string = "textAlign";
[@mel.get] external textDecoration: t => string = "textDecoration";
[@mel.get] external textIndent: t => string = "textIndent";
[@mel.get] external textShadow: t => string = "textShadow";
[@mel.get] external textTransform: t => string = "textTransform";
[@mel.get] external top: t => string = "top";
[@mel.get] external unicodeBidi: t => string = "unicodeBidi";
[@mel.get] external verticalAlign: t => string = "verticalAlign";
[@mel.get] external visibility: t => string = "visibility";
[@mel.get] external voiceFamily: t => string = "voiceFamily";
[@mel.get] external volume: t => string = "volume";
[@mel.get] external whiteSpace: t => string = "whiteSpace";
[@mel.get] external widows: t => string = "widows";
[@mel.get] external width: t => string = "width";
[@mel.get] external wordSpacing: t => string = "wordSpacing";
[@mel.get] external zIndex: t => string = "zIndex";
