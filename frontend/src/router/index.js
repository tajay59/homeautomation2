// Composables
import { createRouter, createWebHistory } from 'vue-router'

const routes = [
  { path: '/', name: 'Home', component: () => import('@/views/Home.vue'), meta:{ transition: 'fade'} }, 
  { path: '/live', name: 'Live', component: () => import('@/views/Live.vue'), meta:{ transition: 'fade'} }, 
  { path: '/dashboard', name: 'Dashboard', component: () => import('@/views/Dashboard.vue'), meta:{ transition: 'fade'} }, 
  { path: '/analysis', name: 'Analysis', component: () => import('@/views/Analysis.vue'), meta:{ transition: 'fade'} }, 
  { path: '/virtual', name: 'Virtual', component: () => import('@/views/Virtual.vue'), meta:{ transition: 'fade'} }, 
 
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes,
})

export default router
