module Impl = (T: {type t;}) => {
  [@bs.get] external data : T.t => string = "data";
  [@bs.get] external length : T.t => int = "length";

  [@bs.send.pipe : T.t] external substringData : (~offset: int, ~count: int) => string = "substringData";
  [@bs.send.pipe : T.t] external appendData : string => unit = "appendData";
  [@bs.send.pipe : T.t] external insertData : (~offset: int, string) => unit = "insertData";
  [@bs.send.pipe : T.t] external deleteData : (~offset: int, ~count: int) => unit = "deleteData";
  [@bs.send.pipe : T.t] external replaceData : (~offset: int, ~count: int, string) => unit = "replaceData";
};

type t = Dom.characterData;

include NodeRe.Impl({ type nonrec t = t; });
include EventTargetRe.Impl({ type nonrec t = t; });
include NonDocumentTypeChildNodeRe.Impl({ type nonrec t = t; });
include ChildNodeRe.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
