<template>
  <div id="app"> 
    <headerComponent/>
  </div>
</template>

<script>
import headerComponent from './components/headerComponent.vue'

export default {
  name: 'App',
  components: {
    headerComponent
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

}
body{
    background-color: #342E37;
    margin: 0;
}
</style>
