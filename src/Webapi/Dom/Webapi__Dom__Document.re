module Impl = (T: {
                 type t;
               }) => {
  external asDocument: T.t => Dom.document = "%identity";

  let asHtmlDocument: T.t => Js.null(Dom.htmlDocument) = [%raw
    {|
    function (document) {
      if (document.doctype) {
          return document.doctype.name === "html" ?  document : null;
      } else {
          return null
      }
    }
  |}
  ];
  [@deprecated
    "Will fail if no doctype is defined, consider using unsafeAsHtmlDocument instead"
  ]
  let asHtmlDocument: T.t => option(Dom.htmlDocument) =
    self => Js.Null.toOption(asHtmlDocument(self));

  external unsafeAsHtmlDocument: T.t => Dom.htmlDocument = "%identity";

  let ofNode = (node: Dom.node): option(T.t) =>
    Webapi__Dom__Node.nodeType(node) == Webapi__Dom__Types.Document
      ? Some(Obj.magic(node)) : None;

  [@mel.get] external characterSet: T.t => string = "characterSet";
  [@mel.get]
  external compatMode: T.t => string /* compatMode enum */ = "compatMode"; /* experimental */
  let compatMode: T.t => Webapi__Dom__Types.compatMode =
    self => Webapi__Dom__Types.decodeCompatMode(compatMode(self));
  [@mel.get] external doctype: T.t => Dom.documentType = "doctype";
  [@mel.get] external documentElement: T.t => Dom.element = "documentElement";
  [@mel.get] external documentURI: T.t => string = "documentURI";
  [@mel.get] external hidden: T.t => bool = "hidden";
  [@mel.get]
  external implementation: T.t => Dom.domImplementation = "implementation";
  [@mel.get] external lastStyleSheetSet: T.t => string = "lastStyleSheetSet";
  [@mel.get] [@mel.return nullable]
  external pointerLockElement: T.t => option(Dom.element) =
    "pointerLockElement"; /* experimental */

  [@mel.get]
  external preferredStyleSheetSet: T.t => string = "preferredStyleSheetSet";
  [@mel.get] [@mel.return nullable]
  external scrollingElement: T.t => option(Dom.element) = "scrollingElement";
  [@mel.get]
  external selectedStyleSheetSet: T.t => string = "selectedStyleSheetSet";
  [@mel.set]
  external setSelectedStyleSheetSet: (T.t, string) => unit =
    "selectedStyleSheetSet";
  [@mel.get]
  external styleSheets: T.t => array(Dom.cssStyleSheet) = "styleSheets"; /* return StyleSheetList, not array */
  [@mel.get] external styleSheetSets: T.t => array(string) = "styleSheetSets";
  [@mel.get]
  external visibilityState: T.t => string /* visibilityState enum */ =
    "visibilityState";
  let visibilityState: T.t => Webapi__Dom__Types.visibilityState =
    self => Webapi__Dom__Types.decodeVisibilityState(visibilityState(self));

  [@mel.send]
  external adoptNode:
    (Dom.element_like('a), [@mel.this] T.t) => Dom.element_like('a) =
    "adoptNode";
  [@mel.send]
  external createAttribute: (string, [@mel.this] T.t) => Dom.attr =
    "createAttribute";
  [@mel.send]
  external createAttributeNS: (string, string, [@mel.this] T.t) => Dom.attr =
    "createAttributeNS";
  [@mel.send]
  external createComment: (string, [@mel.this] T.t) => Dom.comment =
    "createComment";
  [@mel.send]
  external createDocumentFragment: ([@mel.this] T.t) => Dom.documentFragment =
    "createDocumentFragment";
  [@mel.send]
  external createElement: (string, [@mel.this] T.t) => Dom.element =
    "createElement";
  [@mel.send]
  external createElementWithOptions:
    (string, Js.t({..}), [@mel.this] T.t) => Dom.element =
    "createElement"; /* not widely supported */
  [@mel.send]
  external createElementNS: (string, string, [@mel.this] T.t) => Dom.element =
    "createElementNS";
  [@mel.send]
  external createElementNSWithOptions:
    (string, string, Js.t({..}), [@mel.this] T.t) => Dom.element =
    "createElementNS"; /* not widely supported */
  [@mel.send]
  external createEvent: (string /* large enum */, [@mel.this] T.t) => Dom.event =
    "createEvent"; /* discouraged (but not deprecated) in favor of Event constructors */
  [@mel.send]
  external createNodeIterator:
    (Dom.node_like('a), [@mel.this] T.t) => Dom.nodeIterator =
    "createNodeIterator";
  [@mel.send]
  external createNodeIteratorWithWhatToShow:
    (Dom.node_like('a), Webapi__Dom__Types.WhatToShow.t, [@mel.this] T.t) =>
    Dom.nodeIterator =
    "createNodeIterator";
  [@mel.send]
  external createNodeIteratorWithWhatToShowFilter:
    (
      Dom.node_like('a),
      Webapi__Dom__Types.WhatToShow.t,
      Dom.nodeFilter,
      [@mel.this] T.t
    ) =>
    Dom.nodeIterator =
    "createNodeIterator"; /* createProcessingInstruction */
  [@mel.send]
  external createRange: ([@mel.this] T.t) => Dom.range = "createRange";
  [@mel.send]
  external createTextNode: (string, [@mel.this] T.t) => Dom.text =
    "createTextNode";
  [@mel.send]
  external createTreeWalker:
    (Dom.element_like('a), [@mel.this] T.t) => Dom.treeWalker =
    "createTreeWalker";
  [@mel.send]
  external createTreeWalkerWithWhatToShow:
    (
      Dom.element_like('a),
      Webapi__Dom__Types.WhatToShow.t,
      [@mel.this] T.t
    ) =>
    Dom.treeWalker =
    "createTreeWalker";
  [@mel.send]
  external createTreeWalkerWithWhatToShowFilter:
    (
      Dom.element_like('a),
      Webapi__Dom__Types.WhatToShow.t,
      Dom.nodeFilter,
      [@mel.this] T.t
    ) =>
    Dom.treeWalker =
    "createTreeWalker";
  [@mel.send]
  external elementFromPoint: (int, int, [@mel.this] T.t) => Dom.element =
    "elementFromPoint"; /* experimental, but widely supported */
  [@mel.send]
  external elementsFromPoint:
    (int, int, [@mel.this] T.t) => array(Dom.element) =
    "elementsFromPoint"; /* experimental */
  [@mel.send]
  external enableStyleSheetsForSet: (string, [@mel.this] T.t) => unit =
    "enableStyleSheetsForSet";
  [@mel.send]
  external exitPointerLock: ([@mel.this] T.t) => unit = "exitPointerLock"; /* experimental */
  [@mel.send]
  external getAnimations: ([@mel.this] T.t) => array(Dom.animation) =
    "getAnimations"; /* experimental */
  [@mel.send]
  external getElementsByClassName:
    (string, [@mel.this] T.t) => Dom.htmlCollection =
    "getElementsByClassName";
  [@mel.send]
  external getElementsByTagName:
    (string, [@mel.this] T.t) => Dom.htmlCollection =
    "getElementsByTagName";
  [@mel.send]
  external getElementsByTagNameNS:
    (string, string, [@mel.this] T.t) => Dom.htmlCollection =
    "getElementsByTagNameNS";
  [@mel.send]
  external importNode:
    (Dom.element_like('a), [@mel.this] T.t) => Dom.element_like('a) =
    "importNode";
  [@mel.send]
  external importNodeDeep:
    (Dom.element_like('a), [@mel.as {json|true|json}] _, [@mel.this] T.t) =>
    Dom.element_like('a) =
    "importNode";
  [@mel.send]
  external registerElement: (string, unit, [@mel.this] T.t) => Dom.element =
    "registerElement"; /* experimental and deprecated in favor of customElements.define() */
  [@mel.send]
  external registerElementWithOptions:
    (string, Js.t({..}), unit, [@mel.this] T.t) => Dom.element =
    "registerElement"; /* experimental and deprecated in favor of customElements.define() */

  /** XPath stuff */;
  /* createExpression */
  /* createNSResolver */
  /* evaluate */
  /* GlobalEventHandlers interface */
};

type t = Dom.document;

include Webapi__Dom__Node.Impl({
  type nonrec t = t;
});
include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});
include Webapi__Dom__NonElementParentNode.Impl({
  type nonrec t = t;
});
include Webapi__Dom__DocumentOrShadowRoot.Impl({
  ();
});
include Webapi__Dom__ParentNode.Impl({
  type nonrec t = t;
});
include Impl({
  type nonrec t = t;
});
