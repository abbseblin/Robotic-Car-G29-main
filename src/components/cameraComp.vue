<template>
    <div>
        <VideoCapture id="video" uploadUrl="localhost:8080" v-model="videoUrl" />
    </div>
</template>

<script>
import {VideoCapture} from 'vue-media-recorder'

export default {
    data(){
        return {
            imageBase64: null,
            videoUrl: null,
        }
    },
    components:{
        VideoCapture
    }
}
</script>

<style>
#video{
    width: 500px;
}
</style>