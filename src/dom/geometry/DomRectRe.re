type t = Dom.domRect;

[@bs.new] external make : (~x: int, ~y: int, ~width: int, ~height: int) => t = "DOMRect"; /* experimental */

[@bs.get] external top : t => int = "top";
[@bs.get] external bottom : t => int = "bottom";
[@bs.get] external left : t => int = "left";
[@bs.get] external right : t => int = "right";
[@bs.get] external height : t => int = "height";
[@bs.get] external width : t => int = "width";
[@bs.get] external x : t => int = "x";
[@bs.get] external y : t => int = "y";
