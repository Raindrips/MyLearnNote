# Firefox 68: CORS请求不是http

当用户在 Firefox 67 和更早版本中使用 `file:///` URI 打开页面时，页面来源被定义为打开页面的目录。同一目录及其子目录中的资源均被视为具有相同的来源，符合 CORS 同源规则。

为响应 [CVE-2019-11730](https://links.jianshu.com/go?to=https%3A%2F%2Fwww.mozilla.org%2Fen-US%2Fsecurity%2Fadvisories%2Fmfsa2019-21%2F%23CVE-2019-11730)，Firefox 68 及更高版本中使用 `file:///` URI 定义打开页面的来源唯一。 因此，同一目录或其子目录中的其他资源不再满足 CORS 同源规则。这个新的表现通过 `privacy.file_unique_origin` 这一首选项控制，默认启用。

> 目前的解决办法是 在火狐浏览器地址栏输入about:config , 然后选了解风险, 然后搜索这个首选项privacy.file_unique_origin,把值改成false

也可以在html文件中添加 `--allow-file-access-from-files` 来解决。



```csharp
html {
    -ms-text-size-adjust: 100%;
    -webkit-text-size-adjust: 100%;
    --allow-file-access-from-files;
}
```