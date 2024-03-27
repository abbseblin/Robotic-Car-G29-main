<template>
    <div id="header">
        <div class="links">
            <RouterLink class="link" to="/">Go to Home</RouterLink>
            <RouterLink class="link" to="/cam">Go to Camera</RouterLink>
        </div>
        <router-view></router-view>
    </div>
</template>

<script>
export default{
    data(){
        return {
            data: '',
        }
    },
}
</script>

<style>
#header{
    width: 100%;
    height: 4em;
    background-color: aliceblue;
}
.links{
    display: flex;
    justify-content: start;
    height: 4em
}
.link{
    padding: 10px;
    margin: 1em;
    align-self: center;
    border: 0.2em solid #342E37;
    border-radius: 1em;
    background-color: #342E37;
    color: whitesmoke;
    
}
</style>