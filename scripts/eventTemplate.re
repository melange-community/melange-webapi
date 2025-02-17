let typ = Node.Process.argv[2];
let name = Node.Process.argv[3];
let lname = name |> Js.String.toLowerCase;

{j|
  [@mel.send] external add$(name)EventListener : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, [@mel.this] T.t) => unit = "addEventListener";
  [@mel.send] external add$(name)EventListenerWithOptions : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, {. "capture": bool, "once": bool, "passive": bool}, [@mel.this] T.t) => unit = "addEventListener"; /* not widely supported */
  [@mel.send] external add$(name)EventListenerUseCapture : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, [@mel.as {json|true|json}] _, [@mel.this] T.t) => unit = "addEventListener";
  [@mel.send] external remove$(name)EventListener : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, [@mel.this] T.t) => unit = "removeEventListener";
  [@mel.send] external remove$(name)EventListenerWithOptions : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, {. "capture": bool, "passive": bool}, [@mel.this] T.t) => unit = "removeEventListener"; /* not widely supported */
  [@mel.send] external remove$(name)EventListenerUseCapture : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, [@mel.as {json|true|json}] _, [@mel.this] T.t) => unit = "removeEventListener";
|j}
|> Js.log;
