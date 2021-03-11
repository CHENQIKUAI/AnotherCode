import React, { Component } from 'react';
import { BackHandler, Platform } from 'react-native';
import WebView, { WebViewNavigation } from "react-native-webview";

// const url = "https://3g.163.com";
// const url = "https://www.baidu.com";
// const url = "https://redpacket.biqianbao.net/pages/login.html?platform_id=1000";
// const url = "http://47.114.159.142:88/pages/login.html?platform_id=1000";
// const url = "http://47.114.159.142:88/#/pages/login.html?platform_id=1000";
const url = "http://47.114.159.142:8884/ff/#/";

const injectedJavascript = `(function() {
  window.postMessageToApp = function(action) {
    window.ReactNativeWebView.postMessage(JSON.stringify(action));
  };
})()`;

export default class App extends Component {
  webview: WebView<{}> | undefined;
  canGoBack: boolean = false;

  handleHardwareBackPress = () => {
    // 点击back键时间监听函数
    // 该函数若返回false，当前activity则出栈。
    // 若函数返回true，则当前activity不出栈。此时开发者可以自定义相应方式。
    if (this.canGoBack) {
      this.webview?.goBack(); // 根据webview的历史记录往后跳转一个页面。
      return true;
    } else {
      return false;
    }
  }

  componentDidMount() {
    // 监听back键的点击
    if (Platform.OS === "android")
      BackHandler.addEventListener("hardwareBackPress", this.handleHardwareBackPress)
  }

  componentWillUnmount() {
    if (Platform.OS === "android")
      BackHandler.removeEventListener("hardwareBackPress", this.handleHardwareBackPress)
  }

  // 接受html传递过来的消息
  messageHandler = (action: { type: string, payload: any }) => {
    // console.log(action);
  }

  handleNavigationStateChange = (navigationState: WebViewNavigation) => {
    // webview导航状态变化后，获取当前是否可以goBack的信息，保存起来
    console.log(navigationState);
    this.canGoBack = navigationState.canGoBack
  }

  render() {
    return (
      <>
        <WebView
          ref={(webview: WebView) => {
            this.webview = webview;
          }}
          originWhitelist={['*']}
          source={{ uri: url }}
          onMessage={(event) => { this.messageHandler(JSON.parse(event.nativeEvent.data)) }}
          injectedJavaScript={injectedJavascript}
          onNavigationStateChange={this.handleNavigationStateChange}
        ></WebView>
      </>
    );
  }
}
