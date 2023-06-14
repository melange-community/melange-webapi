type t = Dom.svgZoomEvent;

include EventRe.Impl({ type nonrec t = t; });
include UiEventRe.Impl({ type nonrec t = t; });

[@bs.new] external make : string => t = "SVGZoomEvent";
[@bs.new] external makeWithOptions : (string, Js.t({..})) => t = "SVGZoomEvent";

[@bs.get] external zoomRectScreen : t => Dom.svgRect = "zoomRectScreen";
[@bs.get] external previousScale : t => float = "previousScale";
[@bs.get] external previousTranslate : t => Dom.svgPoint = "previousTranslate";
[@bs.get] external newScale : t => float = "newScale";
[@bs.get] external newTranslate : t => Dom.svgPoint = "newTranslate";
