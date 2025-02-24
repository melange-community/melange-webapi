/* internal, moved out of Impl to reduce unnecessary code duplication */
let ofNode = (node: Dom.node): option('a) =>
  Webapi__Dom__Node.nodeType(node) == Webapi__Dom__Types.Element
    ? Some(Obj.magic(node)) : None;

module Impl = (T: {
                 type t;
               }) => {
  let asHtmlElement: T.t => Js.null(Dom.htmlElement) = [%raw
    {|
    function (element) {
      // BEWARE: Assumes "contentEditable" uniquely identifies an HTMLELement
      return element.contentEditable !== undefined ?  element : null;
    }
  |}
  ];
  [@deprecated
    "asHtmlElement uses a weak heuristic, consider using unsafeAsHtmlElement instead"
  ]
  let asHtmlElement: T.t => option(Dom.htmlElement) =
    self => Js.Null.toOption(asHtmlElement(self));

  external unsafeAsHtmlElement: T.t => Dom.htmlElement = "%identity";

  let ofNode: Dom.node => option(T.t) = ofNode;

  [@mel.get] external attributes: T.t => Dom.namedNodeMap = "attributes";
  [@mel.get] external classList: T.t => Dom.domTokenList = "classList";
  [@mel.get] external className: T.t => string = "className";
  [@mel.set] external setClassName: (T.t, string) => unit = "className";
  [@mel.get] external clientHeight: T.t => int = "clientHeight"; /* experimental */
  [@mel.get] external clientLeft: T.t => int = "clientLeft"; /* experimental */
  [@mel.get] external clientTop: T.t => int = "clientTop"; /* experimental */
  [@mel.get] external clientWidth: T.t => int = "clientWidth"; /* experimental */
  [@mel.get] external id: T.t => string = "id";
  [@mel.set] external setId: (T.t, string) => unit = "id";
  [@mel.get] external innerHTML: T.t => string = "innerHTML";
  [@mel.set] external setInnerHTML: (T.t, string) => unit = "innerHTML";
  [@mel.get] external localName: T.t => string = "localName";
  [@mel.get] [@mel.return nullable]
  external namespaceURI: T.t => option(string) = "namespaceURI";
  [@mel.get] external outerHTML: T.t => string = "outerHTML"; /* experimental, but widely supported */
  [@mel.set] external setOuterHTML: (T.t, string) => unit = "outerHTML"; /* experimental, but widely supported */
  [@mel.get] [@mel.return nullable]
  external prefix: T.t => option(string) = "prefix";
  [@mel.get] external scrollHeight: T.t => int = "scrollHeight"; /* experimental, but widely supported */
  [@mel.get] external scrollLeft: T.t => float = "scrollLeft"; /* experimental */
  [@mel.set] external setScrollLeft: (T.t, float) => unit = "scrollLeft"; /* experimental */
  [@mel.get] external scrollTop: T.t => float = "scrollTop"; /* experimental, but widely supported */
  [@mel.set] external setScrollTop: (T.t, float) => unit = "scrollTop"; /* experimental, but widely supported */
  [@mel.get] external scrollWidth: T.t => int = "scrollWidth"; /* experimental */
  [@mel.get] external shadowRoot: T.t => Dom.element = "shadowRoot"; /* experimental */
  [@mel.get] external slot: T.t => string = "slot"; /* experimental */
  [@mel.set] external setSlot: (T.t, string) => unit = "slot"; /* experimental */
  [@mel.get] external tagName: T.t => string = "tagName";

  [@mel.send]
  external attachShadow:
    ({. "mode": string}, [@mel.this] T.t) => Dom.shadowRoot =
    "attachShadow"; /* experimental */
  [@mel.send]
  external attachShadowOpen:
    ([@mel.as {json|{ "mode": "open" }|json}] _, [@mel.this] T.t) =>
    Dom.shadowRoot =
    "attachShadow"; /* experimental */
  [@mel.send]
  external attachShadowClosed:
    ([@mel.as {json|{ "mode": "closed" }|json}] _, [@mel.this] T.t) =>
    Dom.shadowRoot =
    "attachShadow"; /* experimental */
  [@mel.send]
  external animate:
    (Js.t({..}), Js.t({..}), [@mel.this] T.t) => Dom.animation =
    "animate"; /* experimental */
  [@mel.send] [@mel.return nullable]
  external closest: (string, [@mel.this] T.t) => option(Dom.element) =
    "closest"; /* experimental */
  [@mel.send]
  external createShadowRoot: ([@mel.this] T.t) => Dom.shadowRoot =
    "createShadowRoot"; /* experimental AND deprecated (?!) */
  [@mel.send] [@mel.return nullable]
  external getAttribute: (string, [@mel.this] T.t) => option(string) =
    "getAttribute";
  [@mel.send] [@mel.return nullable]
  external getAttributeNS: (string, string, [@mel.this] T.t) => option(string) =
    "getAttributeNS";
  [@mel.send]
  external getBoundingClientRect: ([@mel.this] T.t) => Dom.domRect =
    "getBoundingClientRect";
  [@mel.send]
  external getClientRects: ([@mel.this] T.t) => array(Dom.domRect) =
    "getClientRects";
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
  external hasAttribute: (string, [@mel.this] T.t) => bool = "hasAttribute";
  [@mel.send]
  external hasAttributeNS: (string, string, [@mel.this] T.t) => bool =
    "hasAttributeNS";
  [@mel.send]
  external hasAttributes: ([@mel.this] T.t) => bool = "hasAttributes";
  [@mel.send]
  external insertAdjacentElement:
    (
      string /* insertPosition enum */,
      Dom.element_like('a),
      [@mel.this] T.t
    ) =>
    unit =
    "insertAdjacentElement"; /* experimental, but widely supported */
  let insertAdjacentElement:
    (Webapi__Dom__Types.insertPosition, Dom.element_like('a), T.t) => unit =
    (position, element, self) =>
      insertAdjacentElement(
        Webapi__Dom__Types.encodeInsertPosition(position),
        element,
        self,
      );
  [@mel.send]
  external insertAdjacentHTML:
    (string /* insertPosition enum */, string, [@mel.this] T.t) => unit =
    "insertAdjacentHTML"; /* experimental, but widely supported */
  let insertAdjacentHTML:
    (Webapi__Dom__Types.insertPosition, string, T.t) => unit =
    (position, text, self) =>
      insertAdjacentHTML(
        Webapi__Dom__Types.encodeInsertPosition(position),
        text,
        self,
      );
  [@mel.send]
  external insertAdjacentText:
    (string /* insertPosition enum */, string, [@mel.this] T.t) => unit =
    "insertAdjacentText"; /* experimental, but widely supported */
  let insertAdjacentText:
    (Webapi__Dom__Types.insertPosition, string, T.t) => unit =
    (position, text, self) =>
      insertAdjacentText(
        Webapi__Dom__Types.encodeInsertPosition(position),
        text,
        self,
      );
  [@mel.send] external matches: (string, [@mel.this] T.t) => bool = "matches"; /* experimental, but widely supported */
  [@mel.send]
  external releasePointerCapture: (Dom.eventPointerId, [@mel.this] T.t) => unit =
    "releasePointerCapture";
  [@mel.send]
  external removeAttribute: (string, [@mel.this] T.t) => unit =
    "removeAttribute";
  [@mel.send]
  external removeAttributeNS: (string, string, [@mel.this] T.t) => unit =
    "removeAttributeNS";
  [@mel.send]
  external requestFullscreen: ([@mel.this] T.t) => unit = "requestFullscreen"; /* experimental */
  [@mel.send]
  external requestPointerLock: ([@mel.this] T.t) => unit =
    "requestPointerLock"; /* experimental */
  [@mel.send]
  external scrollIntoView: ([@mel.this] T.t) => unit = "scrollIntoView"; /* experimental, but widely supported */
  [@mel.send]
  external scrollIntoViewNoAlignToTop:
    ([@mel.as {json|true|json}] _, [@mel.this] T.t) => unit =
    "scrollIntoView"; /* experimental, but widely supported */
  [@mel.send]
  external scrollIntoViewWithOptions:
    (
      {
        .
        "behavior": string,
        "block": string,
      },
      [@mel.this] T.t
    ) =>
    unit =
    "scrollIntoView"; /* experimental */
  [@mel.send]
  external scrollBy: (float, float, [@mel.this] T.t) => unit = "scrollBy";
  [@mel.send]
  external scrollByWithOptions:
    (
      {
        .
        "top": float,
        "left": float,
        "behavior": string,
      },
      [@mel.this] T.t
    ) =>
    unit =
    "scrollBy";
  [@mel.send]
  external scrollTo: (float, float, [@mel.this] T.t) => unit = "scrollTo";
  [@mel.send]
  external scrollToWithOptions:
    (
      {
        .
        "top": float,
        "left": float,
        "behavior": string,
      },
      [@mel.this] T.t
    ) =>
    unit =
    "scrollTo";
  [@mel.send]
  external setAttribute: (string, string, [@mel.this] T.t) => unit =
    "setAttribute";
  [@mel.send]
  external setAttributeNS: (string, string, string, [@mel.this] T.t) => unit =
    "setAttributeNS";
  [@mel.send]
  external setPointerCapture: (Dom.eventPointerId, [@mel.this] T.t) => unit =
    "setPointerCapture";

  /* GlobalEventHandlers interface */
  /* Not sure this should be exposed, since EventTarget seems like a better API */

  [@mel.set]
  external setOnClick: (T.t, Dom.mouseEvent => unit) => unit = "onclick";
};

/* TODO: This doesn't work. Why?
   module Tree (T: { type t; }) => {
     include NodeRe.Impl { type t = Type };
     include EventTargetRe.Impl { type t = Type };
     include Impl { type t = Type };
   };

   include Tree { type t = Dom.element };
   */

type t = Dom.element;

include Webapi__Dom__Node.Impl({
  type nonrec t = t;
});
include Webapi__Dom__EventTarget.Impl({
  type nonrec t = t;
});
include Webapi__Dom__GlobalEventHandlers.Impl({
  type nonrec t = t;
});
include Webapi__Dom__ParentNode.Impl({
  type nonrec t = t;
});
include Webapi__Dom__NonDocumentTypeChildNode.Impl({
  type nonrec t = t;
});
include Webapi__Dom__ChildNode.Impl({
  type nonrec t = t;
});
include Webapi__Dom__Slotable.Impl({
  type nonrec t = t;
});
include Impl({
  type nonrec t = t;
});
