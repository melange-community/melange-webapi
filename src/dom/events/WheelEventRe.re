type t = Dom.wheelEvent;

include EventRe.Impl({ type nonrec t = t; });
include UiEventRe.Impl({ type nonrec t = t; });

[@bs.new] external make : string => t = "WheelEvent";
[@bs.new] external makeWithOptions : (string, Js.t({..})) => t = "WheelEvent";

[@bs.get] external deltaX : t => float = "deltaX";
[@bs.get] external deltaY : t => float = "deltaY";
[@bs.get] external deltaZ : t => float = "deltaZ";
[@bs.get] external deltaMode : t => int = "deltaMode";
let deltaMode: t => DomTypesRe.deltaMode = (self) =>
  DomTypesRe.decodeDeltaMode(deltaMode(self));
