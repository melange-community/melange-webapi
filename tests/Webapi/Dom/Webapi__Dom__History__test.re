open Webapi.Dom;
open History;

let _ = length(history);
let _ = scrollRestoration(history);
let _ = setScrollRestoration(history, true);
let _ = state(history);

back(history);
forward(history);
go((-2), history);
pushState(state(history), "My title", "http://...", history);
pushState({"foo": "bar"}, "My title", "http://...", history);
replaceState({"foo": "bar"}, "My title", "http://...", history);
