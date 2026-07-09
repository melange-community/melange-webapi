let el = Webapi.Dom.document |> Webapi.Dom.Document.createElement("div");

let body: Dom.element =
  Webapi.Dom.Document.asHtmlDocument(Webapi.Dom.document)
  ->Belt.Option.flatMap(Webapi.Dom.HtmlDocument.body)
  ->TestHelpers.unsafelyUnwrapOption;

Webapi.Dom.Element.setInnerText(el, "Hello There");
Webapi.Dom.Element.setAttribute(
  "style",
  "margin-top: 800px; margin-bottom: 800px",
  el,
);
Webapi.Dom.Element.appendChild(body, el);

let handler = (entries, observer) => {
  Js.Array.forEach(
    ~f=
      entry => {
        open Webapi.IntersectionObserver.IntersectionObserverEntry;
        Js.log(time(entry));
        Js.log(rootBounds(entry));
        Js.log(boundingClientRect(entry));
        Js.log(intersectionRect(entry));
        Js.log(isIntersecting(entry));
        Js.log(intersectionRatio(entry));
        Js.log(target(entry));
      },
    entries,
  );

  Webapi.IntersectionObserver.unobserve(observer, el);
};

let observer: Webapi.IntersectionObserver.t =
  Webapi.IntersectionObserver.make(handler);

Webapi.IntersectionObserver.observe(observer, el);
Webapi.IntersectionObserver.unobserve(observer, el);
Webapi.IntersectionObserver.observe(observer, el);
Webapi.IntersectionObserver.disconnect(observer);
