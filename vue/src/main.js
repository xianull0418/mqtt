import Vue from 'vue'

import Cookies from 'js-cookie'

import Element from 'element-ui'
import './assets/styles/element-variables.scss'

import '@/assets/styles/index.scss' // global css
import '@/assets/styles/ruoyi.scss' // ruoyi css
import App from './App'
import store from './store'
import router from './router'
import directive from './directive' // directive
import plugins from './plugins' // plugins
import { download } from '@/utils/request'

import './assets/icons' // icon
import './permission' // permission control
import { getDicts } from "@/api/system/dict/data";
import { getConfigKey } from "@/api/system/config";
import { parseTime, resetForm, addDateRange, selectDictLabel, selectDictLabels, handleTree } from "@/utils/ruoyi";
// 分页组件
import Pagination from "@/components/Pagination";
// 自定义表格工具组件
import RightToolbar from "@/components/RightToolbar"
// 富文本组件
import Editor from "@/components/Editor"
// 文件上传组件
import FileUpload from "@/components/FileUpload"
// 图片上传组件
import ImageUpload from "@/components/ImageUpload"
// 字典标签组件
import DictTag from '@/components/DictTag'
// 头部标签组件
import VueMeta from 'vue-meta'
// 字典数据组件
import DictData from '@/components/DictData'
// Echart
import echarts from 'echarts'
// 一键复制粘贴板组件
import VueClipboard from 'vue-clipboard2'
// Mqtt工具
import mqttTool from '@/utils/mqttTool'

import ItemWrap from './views/bigScreen/components/item-wrap/item-wrap.vue'
import Message from './views/bigScreen/components/message/message.vue'
import Reacquire from './views/bigScreen/components/reacquire/reacquire.vue'
import Echart from './views/bigScreen/components/echart/index.vue'

import {loading,borderBox13,digitalFlop,capsuleChart,borderBox8} from '@jiaminghi/data-view'
import * as filters from '@/directive/filters'

require('./mock/mock')//是否使用mock

// datav组件
Vue.use(loading)
Vue.use(borderBox13)
Vue.use(borderBox8)
Vue.use(digitalFlop)
Vue.use(capsuleChart)

// 自定义组件
Vue.component("Echart",Echart)
Vue.component("ItemWrap",ItemWrap)
Vue.component("Message",Message)
Vue.component("Reacquire",Reacquire)




// 全局方法挂载
Vue.prototype.getDicts = getDicts
Vue.prototype.getConfigKey = getConfigKey
Vue.prototype.parseTime = parseTime
Vue.prototype.resetForm = resetForm
Vue.prototype.addDateRange = addDateRange
Vue.prototype.selectDictLabel = selectDictLabel
Vue.prototype.selectDictLabels = selectDictLabels
Vue.prototype.download = download
Vue.prototype.handleTree = handleTree
Vue.prototype.$echarts = echarts
Vue.prototype.$mqttTool = mqttTool

// 全局组件挂载
Vue.component('DictTag', DictTag)
Vue.component('Pagination', Pagination)
Vue.component('RightToolbar', RightToolbar)
Vue.component('Editor', Editor)
Vue.component('FileUpload', FileUpload)
Vue.component('ImageUpload', ImageUpload)
Vue.use(VueClipboard)
Vue.use(directive)
Vue.use(plugins)
Vue.use(VueMeta)
DictData.install()

// 全局数据过滤器
Object.keys(filters).forEach(k => Vue.filter(k, filters[k]));
/**
 * If you don't want to use mock-server
 * you want to use MockJs for mock api
 * you can execute: mockXHR()
 *
 * Currently MockJs will be used in the production environment,
 * please remove it before going online! ! !
 */

Vue.use(Element, {
  size: Cookies.get('size') || 'medium' // set element-ui default size
})

Vue.config.productionTip = false

new Vue({
  el: '#app',
  router,
  store,
  render: h => h(App)
})

// 带有边框
Element.Table.props.border = {
  default:true,
  type:Boolean
}
