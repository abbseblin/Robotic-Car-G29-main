<template>
    <div id="main">
        <div id="titleParent">
            <h1>Control Panel for Robotic Car</h1>
            <div id="divider"></div>
        </div>

        <div id="boxParent">
            <div class="buttons">
                <div class="buttonParent">
                    <button class="driveButtons" id="forward" @mousedown="SetMotorDir(1)"
                        @mouseup="SetMotorDir(2)">Forward</button>
                    <div id="lowerButtons">
                        <button class="driveButtons" id="left" @mousedown="SetServoDir(20)" @mouseup="SetServoDir(90)">left</button>
                        <button class="driveButtons" id="backward" @mousedown="SetMotorDir(0)"
                            @mouseup="SetMotorDir(2)">Backward</button>
                        <button class="driveButtons" id="right" @mousedown="SetServoDir(160)" @mouseup="SetServoDir(90)">right</button>
                    </div>
                </div>

                <div class="buttonParent">
                    <label id="speedLabel" for="slider">Speed: {{ MotorSpeed }}</label>
                    <input id="slider" type="range" v-model=MotorSpeed min=0 max=1023 @input="SetMotorSpeed(MotorSpeed)">
                </div>
            </div>
        </div>
    </div>
</template>
  
<script>
import { db, set, ref } from '@/components/firebase-connect'; // Adjust the path accordingly


document.addEventListener('keydown', function(event) {
    switch (event.key) {
        case "w":
        console.log("'w' key was pressed!");
        document.getElementById("forward").classList.add("buttonHover");
        document.getElementById("forward").dispatchEvent(new Event('mousedown'));
            break;

        case "a":
        console.log("'w' key was pressed!");
        document.getElementById("left").classList.add("buttonHover");
        document.getElementById("left").dispatchEvent(new Event('mousedown'));
            break;

        case "s":
        console.log("'w' key was pressed!");
        document.getElementById("backward").classList.add("buttonHover");
        document.getElementById("backward").dispatchEvent(new Event('mousedown'));
            break;
        
        case "d":
        console.log("'w' key was pressed!");
        document.getElementById("right").classList.add("buttonHover");
        document.getElementById("right").dispatchEvent(new Event('mousedown'));
            break;    

        default:
            break;
    }
});

document.addEventListener('keyup', function(event) {
    switch (event.key) {
        case "w":
        console.log("'w' key was pressed!");
        document.getElementById("forward").classList.remove("buttonHover");
        document.getElementById("forward").dispatchEvent(new Event('mouseup'));
            break;

        case "a":
        console.log("'w' key was pressed!");
        document.getElementById("left").classList.remove("buttonHover");
        document.getElementById("left").dispatchEvent(new Event('mouseup'));
            break;

        case "s":
        console.log("'w' key was pressed!");
        document.getElementById("backward").classList.remove("buttonHover");
        document.getElementById("backward").dispatchEvent(new Event('mouseup'));
            break;
        
        case "d":
        console.log("'w' key was pressed!");
        document.getElementById("right").classList.remove("buttonHover");
        document.getElementById("right").dispatchEvent(new Event('mouseup'));
            break;    
    
        default:
            break;
    }
});

export default {
    data() {
        return {
            data: '',
            MotorDir: 0,
            MotorSpeed: 1023,
            servoAngle: 0
        };
    },
    components: {
  },
    methods: {
        SetMotorSpeed(value) {
            const speedValue = parseInt(value, 10);
            set(ref(db, 'motorSpeed'), {
                MotorSpeed: speedValue,
            });
        },
        SetMotorDir(value) {
            set(ref(db, 'motorDir'), {
                MotorDir: value
            })
        },
        SetServoDir(angle){
            set(ref(db, 'servoAngle'),{
                servoAngle: angle
            })
        }
    },
};
</script>

<style scoped>
template{
    margin: 0;
}

#main {
    display: flex;
    flex-direction: column;
}

#titleParent {
    display: flex;
    justify-content: center;
    flex-direction: column;
}

h1 {
    color: azure;
    font-size: 3em;
}

#divider {
    align-self: center;
    width: 94vw;
    height: 1vh;
    background-color: azure;
    margin-bottom: 2vh;
}

#boxParent {
    display: flex;
    flex-direction: row;
    justify-content: space-evenly;
    height: auto;
}

.buttonParent {
    display: flex;
    justify-content: center;
    flex-direction: column;
    width: auto;
    height: 35vh;
    border: 0.2em solid azure;
    border-radius: 1em;
    background-color: azure;
    margin: 2em;
    padding: 1em;
}

.buttons {
    height: auto;
    width: auto;
    display: flex;
}

#lowerButtons {
    display: flex;
    justify-content: center;
}

.driveButtons {
    padding: 0.5em;
    margin: 0.5em;
    width: 6vw;
    height: 12vh;
    display: inline-block;
    text-decoration: none;
    cursor: pointer;
    border: 1px solid #3498db;
    border-radius: 5px;
    color: #ffffff;
    background-color: #3498db;
    align-self: center;
    text-align: center;
    box-shadow: 0 8px 12px rgba(52, 152, 219, 0.3);
}

.driveButtons:hover {
    background-color: #2980b9;
    box-shadow: 0 8px 12px rgba(52, 152, 219, 0.5);
}

.buttonHover{
    background-color: #2980b9;
    box-shadow: 0 8px 12px rgba(52, 152, 219, 0.5);
}

#slider {
    width: 20vw;
    align-self: center;
    margin: 2em;

}

#speedLabel {
    font-size: 2em;
}
</style>
