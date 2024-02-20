<template>
    <div>
        <button id="forward" @mousedown="SetMotorDir(1)" @mouseup="SetMotorDir(2)">Forward</button>
        <button id="forward" @mousedown="SetMotorDir(0)" @mouseup="SetMotorDir(2)">Backward</button>
        <input id="slider" type="range" v-model=MotorSpeed min=0 max=1023 @input="SetMotorSpeed(MotorSpeed)">
    </div>
</template>
  
<script>
import { db, set, ref } from '@/components/firebase-connect'; // Adjust the path accordingly

export default {
    data() {
        return {
            data: '',
            MotorDir: 0,
            MotorSpeed: 1023,
        };
    },
    methods: {
        SetMotorSpeed(value) {
            set(ref(db, 'motorSpeed'), {
                MotorSpeed: value,
            });
        },
        SetMotorDir(value){
            set(ref(db, 'motorDir'), {
                MotorDir: value
            })
        }
    },
};
</script>
  
<style scoped>
div {
    display: flex;
    flex-direction: column;
    align-items: center;
    gap: 20px;
    padding: 20px;
    background-color: #121212;
    /* Dark background */
    color: #e0e0e0;
    /* Light text color for contrast */
}

button {
    background-color: #333;
    color: #fff;
    border: none;
    padding: 10px 20px;
    border-radius: 5px;
    cursor: pointer;
    transition: background-color 0.3s, transform 0.1s;
}

button:hover {
    background-color: #444;
}

button:active {
    background-color: #555;
    transform: scale(0.98);
    /* Subtle press effect */
}

p {
    font-size: 1.2rem;
}

/* Style adjustments for input and range if used later */
/* input[type="text"], input[type="range"] {
    padding: 10px;
    border-radius: 5px;
    border: 1px solid #333;
    background-color: #222;
    color: #fff;
    outline: none;
  }
  
  input[type="range"] {
    -webkit-appearance: none;
    width: 100%;
    background: #333;
  }
  
  input[type="range"]::-webkit-slider-thumb {
    -webkit-appearance: none;
    appearance: none;
    width: 20px;
    height: 20px;
    background: #777;
    cursor: pointer;
  } */
</style>
  