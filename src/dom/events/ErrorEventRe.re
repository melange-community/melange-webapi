type t = Dom.errorEvent;

include EventRe.Impl({ type nonrec t = t; });

[@bs.new] external make : string => t = "ErrorEvent";
[@bs.new] external makeWithOptions : (string, Js.t({..})) => t = "ErrorEvent";

[@bs.get] external message : t => string = "message";
[@bs.get] external filename : t => string = "filename";
[@bs.get] external lineno : t => int = "lineno";
[@bs.get] external colno : t => int = "colno";
[@bs.get] external error : t => Js.t({..}) = "error";