type t = Dom.history;
type state; /* TODO: should be "anything that can be serializable" apparently */

[@mel.get] external length: t => int = "length";
[@mel.get] external scrollRestoration: t => bool = "scrollRestoration"; /* experimental */
[@mel.set]
external setScrollRestoration: (t, bool) => unit = "scrollRestoration"; /* experimental */
[@mel.get] external state: t => state = "state";

[@mel.send] external back: ([@mel.this] t) => unit = "back";
[@mel.send] external forward: ([@mel.this] t) => unit = "forward";
[@mel.send] external go: (int, [@mel.this] t) => unit = "go";
[@mel.send]
external pushState: (state, string, string, [@mel.this] t) => unit =
  "pushState";
[@mel.send]
external replaceState: (state, string, string, [@mel.this] t) => unit =
  "replaceState";
