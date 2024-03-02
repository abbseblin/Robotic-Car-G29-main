<template>
  <div id="app">
    <firebaseData />
  </div>
</template>

<script>
import firebaseData from './components/firebase-data.vue'

export default {
  name: 'App',
  components: {
    firebaseData
  }
}
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 30px;
}
body{
    background-color: #342E37;
    margin: 0;
}
</style>
