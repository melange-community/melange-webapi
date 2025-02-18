module Impl = (T: {
                 type t;
               }) => {
  [@mel.get] external data: T.t => string = "data";
  [@mel.get] external length: T.t => int = "length";

  [@mel.send]
  external substringData:
    (~offset: int, ~count: int, [@mel.this] T.t) => string =
    "substringData";
  [@mel.send]
  external appendData: (string, [@mel.this] T.t) => unit = "appendData";
  [@mel.send]
  external insertData: (~offset: int, string, [@mel.this] T.t) => unit =
    "insertData";
  [@mel.send]
  external deleteData: (~offset: int, ~count: int, [@mel.this] T.t) => unit =
    "deleteData";
  [@mel.send]
  external replaceData:
    (~offset: int, ~count: int, string, [@mel.this] T.t) => unit =
    "replaceData";
};

type t = Dom.characterData;

include Webapi__Dom__Node.Impl({
  type nonrec t = t;
});
include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});
include Webapi__Dom__NonDocumentTypeChildNode.Impl({
  type nonrec t = t;
});
include Webapi__Dom__ChildNode.Impl({
  type nonrec t = t;
});
include Impl({
  type nonrec t = t;
});
