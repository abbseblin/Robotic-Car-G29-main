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
  