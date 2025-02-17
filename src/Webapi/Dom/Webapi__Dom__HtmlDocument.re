module Impl = (T: {
                 type t;
               }) => {
  type t_htmlDocument = T.t;

  [@mel.get] [@mel.return nullable]
  external activeElement: t_htmlDocument => option(Dom.element) =
    "activeElement";
  [@mel.get] [@mel.return nullable]
  external body: t_htmlDocument => option(Dom.element) = "body"; /* returns option HTMLBodyElement */
  [@mel.set] external setBody: (t_htmlDocument, Dom.element) => unit = "body"; /* accepth HTMLBodyElement */
  [@mel.get] external cookie: t_htmlDocument => string = "cookie";
  [@mel.set] external setCookie: (t_htmlDocument, string) => unit = "cookie";
  [@mel.get] [@mel.return nullable]
  external defaultView: t_htmlDocument => option(Dom.window) = "defaultView";
  [@mel.get]
  external designMode: t_htmlDocument => string /* designMode enum */ =
    "designMode";
  let designMode: t_htmlDocument => Webapi__Dom__Types.designMode =
    self => Webapi__Dom__Types.decodeDesignMode(designMode(self));
  [@mel.set]
  external setDesignMode:
    (t_htmlDocument, string /* designMode enum */) => unit =
    "designMode";
  let setDesignMode: (t_htmlDocument, Webapi__Dom__Types.designMode) => unit =
    (self, value) =>
      setDesignMode(self, Webapi__Dom__Types.encodeDesignMode(value));
  [@mel.get] external dir: t_htmlDocument => string /* dir enum */ = "dir";
  let dir: t_htmlDocument => Webapi__Dom__Types.dir =
    self => Webapi__Dom__Types.decodeDir(dir(self));
  [@mel.set]
  external setDir: (t_htmlDocument, string /* dir enum */) => unit = "dir";
  let setDir: (t_htmlDocument, Webapi__Dom__Types.dir) => unit =
    (self, value) => setDir(self, Webapi__Dom__Types.encodeDir(value));
  [@mel.get] [@mel.return nullable]
  external domain: t_htmlDocument => option(string) = "domain";
  [@mel.set] external setDomain: (t_htmlDocument, string) => unit = "domain";
  [@mel.get] external embeds: t_htmlDocument => Dom.nodeList = "embeds";
  [@mel.get] external forms: t_htmlDocument => Dom.htmlCollection = "forms";
  [@mel.get] external head: t_htmlDocument => Dom.element = "head"; /* returns HTMLHeadElement */
  [@mel.get] external images: t_htmlDocument => Dom.htmlCollection = "images";
  [@mel.get] external lastModified: t_htmlDocument => string = "lastModified";
  [@mel.get] external links: t_htmlDocument => Dom.nodeList = "links";
  [@mel.get] external location: t_htmlDocument => Dom.location = "location";
  [@mel.set]
  external setLocation: (t_htmlDocument, string) => unit = "location";
  [@mel.get]
  external plugins: t_htmlDocument => Dom.htmlCollection = "plugins";
  [@mel.get]
  external readyState: t_htmlDocument => string /* enum */ = "readyState";
  let readyState: t_htmlDocument => Webapi__Dom__Types.readyState =
    self => Webapi__Dom__Types.decodeReadyState(readyState(self));
  [@mel.get] external referrer: t_htmlDocument => string = "referrer";
  [@mel.get]
  external scripts: t_htmlDocument => Dom.htmlCollection = "scripts";
  [@mel.get] external title: t_htmlDocument => string = "title";
  [@mel.set] external setTitle: (t_htmlDocument, string) => unit = "title";
  [@mel.get] external url: t_htmlDocument => string = "URL";

  [@mel.send] external close: ([@mel.this] t_htmlDocument) => unit = "close";
  [@mel.send]
  external execCommand:
    (string, bool, Js.null(string), [@mel.this] t_htmlDocument) => bool =
    "execCommand";
  let execCommand: (string, bool, option(string), t_htmlDocument) => bool =
    (command, show, value, self) =>
      execCommand(command, show, Js.Null.fromOption(value), self);
  [@mel.send]
  external getElementsByName:
    (string, [@mel.this] t_htmlDocument) => Dom.nodeList =
    "getElementsByName";
  [@mel.send]
  external getSelection: ([@mel.this] t_htmlDocument) => Dom.selection =
    "getSelection";
  [@mel.send]
  external hasFocus: ([@mel.this] t_htmlDocument) => bool = "hasFocus";
  [@mel.send] external open_: ([@mel.this] t_htmlDocument) => unit = "open";
  [@mel.send]
  external queryCommandEnabled: (string, [@mel.this] t_htmlDocument) => bool =
    "queryCommandEnabled";
  [@mel.send]
  external queryCommandIndeterm: (string, [@mel.this] t_htmlDocument) => bool =
    "queryCommandIndeterm";
  [@mel.send]
  external queryCommandSupported: (string, [@mel.this] t_htmlDocument) => bool =
    "queryCommandSupported";
  [@mel.send]
  external queryCommandValue: (string, [@mel.this] t_htmlDocument) => string =
    "queryCommandValue";
  [@mel.send]
  external write: (string, [@mel.this] t_htmlDocument) => unit = "write";
  [@mel.send]
  external writeln: (string, [@mel.this] t_htmlDocument) => unit = "writeln";
};

type t = Dom.htmlDocument;

include Webapi__Dom__Node.Impl({
  type nonrec t = t;
});
include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});
include Webapi__Dom__GlobalEventHandlers.Impl({
  type nonrec t = t;
});
include Webapi__Dom__Document.Impl({
  type nonrec t = t;
});
include Impl({
  type nonrec t = t;
});
