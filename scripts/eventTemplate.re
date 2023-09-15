
let typ = Node.Process.argv[2];
let name = Node.Process.argv[3];
let lname = name |> Js.String.toLowerCase;

{j|
  [@mel.send.pipe : T.t] external add$(name)EventListener : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit) => unit = "addEventListener";
  [@mel.send.pipe : T.t] external add$(name)EventListenerWithOptions : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@mel.send.pipe : T.t] external add$(name)EventListenerUseCapture : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, [@mel.as {json|true|json}] _) => unit = "addEventListener";
  [@mel.send.pipe : T.t] external remove$(name)EventListener : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit) => unit = "removeEventListener";
  [@mel.send.pipe : T.t] external remove$(name)EventListenerWithOptions : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@mel.send.pipe : T.t] external remove$(name)EventListenerUseCapture : ([@mel.as "$(lname)"] _, Dom.$(typ) => unit, [@mel.as {json|true|json}] _) => unit = "removeEventListener";
|j} |> Js.log;
