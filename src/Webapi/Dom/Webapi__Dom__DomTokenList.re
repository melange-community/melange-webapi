type t = Dom.domTokenList;

[@mel.get] external length: t => int = "length";

[@mel.send] [@mel.return nullable]
external item: (int, [@mel.this] t) => option(string) = "item";
[@mel.send] external add: (string, [@mel.this] t) => unit = "add";
[@mel.send] [@mel.variadic]
external addMany: (array(string), [@mel.this] t) => unit = "add";
[@mel.send] external contains: (string, [@mel.this] t) => bool = "contains";
/* entries: iterator API, should have language support */
[@mel.send]
external forEach: ((string, int) => unit, [@mel.this] t) => unit = "forEach";
/* keys: iterator API, should have language support */
[@mel.send] external remove: (string, [@mel.this] t) => unit = "remove";
[@mel.send] [@mel.variadic]
external removeMany: (array(string), [@mel.this] t) => unit = "remove";
[@mel.send]
external replace: (string, string, [@mel.this] t) => unit = "replace"; /* experimental */
[@mel.send] external supports: (string, [@mel.this] t) => bool = "supports"; /* experimental, Content Management Level 1 */
[@mel.send] external toggle: (string, [@mel.this] t) => bool = "toggle";
[@mel.send]
external toggleForced:
  (string, [@mel.as {json|true|json}] _, [@mel.this] t) => bool =
  "toggle";
[@mel.send] external toString: ([@mel.this] t) => string = "toString";
/* values: iterator API, should have language support */

[@mel.get] external value: t => string = "value"; /* experimental, from being merged with domSettableTokenList */
[@mel.set] external setValue: (t, string) => unit = "value"; /* experimental, from being merged with domSettableTokenList */
