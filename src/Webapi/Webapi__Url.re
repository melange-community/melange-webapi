module URLSearchParams = {
  type t;

  [@mel.new] external make: string => t = "URLSearchParams";
  [@mel.new]
  external makeWithDict: Js.Dict.t(string) => t = "URLSearchParams";
  [@mel.new]
  external makeWithArray: array((string, string)) => t = "URLSearchParams";
  [@mel.send]
  external append: (string, string, [@mel.this] t) => unit = "append";
  [@mel.send] external delete: (string, [@mel.this] t) => unit = "delete";
  [@mel.send]
  external entries: ([@mel.this] t) => Js.Array.array_like((string, string)) =
    "entries";
  [@mel.send]
  external forEach:
    ([@mel.uncurry] ((string, string) => unit), [@mel.this] t) => unit =
    "forEach";
  [@mel.return nullable] [@mel.send]
  external get: (string, [@mel.this] t) => option(string) = "get";
  [@mel.send]
  external getAll: (string, [@mel.this] t) => array(string) = "getAll";
  [@mel.send] external has: (string, [@mel.this] t) => bool = "has";
  [@mel.send]
  external keys: ([@mel.this] t) => Js.Array.array_like(string) = "keys";
  [@mel.send] external set: (string, string, [@mel.this] t) => unit = "set";
  [@mel.send] external sort: ([@mel.this] t) => unit = "sort";
  [@mel.send] external toString: ([@mel.this] t) => string = "toString";
  [@mel.send]
  external values: ([@mel.this] t) => Js.Array.array_like(string) = "values";
};

type t;

[@mel.new] external make: string => t = "URL";

/** Deprecated, use [makeWith] instead. */
[@deprecated "Use [makeWith] instead."] [@mel.new]
external makeWithBase: (string, string) => t = "URL";

/** @since 0.19.0 */
[@mel.new]
external makeWith: (string, ~base: string) => t = "URL";

[@mel.get] external hash: t => string = "hash";
[@mel.set] external setHash: (t, string) => unit = "hash";
[@mel.get] external host: t => string = "host";
[@mel.set] external setHost: (t, string) => unit = "host";
[@mel.get] external hostname: t => string = "hostname";
[@mel.set] external setHostname: (t, string) => unit = "hostname";
[@mel.get] external href: t => string = "href";
[@mel.set] external setHref: (t, string) => unit = "href";
[@mel.get] external origin: t => string = "origin";
[@mel.get] external password: t => string = "password";
[@mel.set] external setPassword: (t, string) => unit = "password";
[@mel.get] external pathname: t => string = "pathname";
[@mel.set] external setPathname: (t, string) => unit = "pathname";
[@mel.get] external port: t => string = "port";
[@mel.set] external setPort: (t, string) => unit = "port";
[@mel.get] external protocol: t => string = "protocol";
[@mel.set] external setProtocol: (t, string) => unit = "protocol";
[@mel.get] external search: t => string = "search";
[@mel.set] external setSearch: (t, string) => unit = "search";
[@mel.get] external searchParams: t => URLSearchParams.t = "searchParams";
[@mel.get] external username: t => string = "username";
[@mel.set] external setUsername: (t, string) => unit = "username";
[@mel.get] external toJson: t => string = "toJson";

[@mel.scope "URL"]
external createObjectURL: Webapi__File.t => string = "createObjectURL";
[@mel.scope "URL"]
external revokeObjectURL: string => unit = "revokeObjectURL";
