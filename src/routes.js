import firebaseData from "./components/firebase-data.vue"
import cameraComp from "./components/cameraComp.vue"

export default[
    {path:'/', component: firebaseData},
    {path:'/cam', component: cameraComp}
]