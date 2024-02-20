import { initializeApp } from 'firebase/app';
import { getDatabase, ref, push, set, update } from 'firebase/database';

const firebaseConfig ={
    apiKey: "AIzaSyBE1C15MxYr7Xcg3gpfnMeiNcpsJnGGmxQ",
    authDomain: "robotic-car-g29.firebaseapp.com",
    databaseURL: "https://robotic-car-g29-default-rtdb.europe-west1.firebasedatabase.app",
    projectId: "robotic-car-g29",
    storageBucket: "robotic-car-g29.appspot.com",
    messagingSenderId: "442771249180",
    appId: "1:442771249180:web:d7d801147c8a7ee27327d9",
    measurementId: "G-59BQFC45CE"
};

const firebaseApp = initializeApp(firebaseConfig);
const db = getDatabase(firebaseApp);

export { db, ref, push, set, update };