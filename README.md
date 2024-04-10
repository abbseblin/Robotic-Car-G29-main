# legobil styrd med egenbyggd kontroll via firebase

## Projektbeskrivning 

Jag har byggt en bil med lego technic som går att styra med en egenbyggd kontroll som gör det möjligt att köra framåt, backa, och svänga.
Förutom hårdvaran så har jag även byggt en hemsida med Vue som gör det möjligt att styra bilen från datorn utan den egenbyggda kontrollen samt se en live feed av det bilen ser.
Detta gör det möjligt att köra bilen fastän man inte ser den. 

Bilen är utrustad med två motorer vilket gör den starkare så att den klarar av vikten av mobilen och powerbanken. Den är även utrustad med en servo som medför att det går att svänga med bilen. 

För att kunna se en live feed från mobilkameran krävs appen Iriun Webcam både i mobilen och i datorn. Den medför att man kan läsa data från mobilens kamera genom att man "lurar" datorn till att tro att mobilens kamera är datorns webcam vilket sen läses av ett bibliotek som heter Vue-Media-Recorder.

<img src="https://github.com/abbseblin/Robotic-Car-G29-main/blob/master/images/White%20Abstract%20Dot%20Grid%20Bullet%20Journal.png" alt="drawing" height="400"/>

Idén från början var att bilen skulle styras med en Logitech G29 ratt och att kamera feeden skulle ges från en ArduCam mini. Jag märkte sedan att biblioteket för att kunna läsa av datan från ratten var utdaterad vilket resulterade i att jag valde att styra bilen med en egengjord kontroll istället. När jag googlade runt så märkte jag att Arducamen var dyr att köpa vilket gjorde att jag valde en annan billigare kamera istället. När jag väl fått den kameran att fungera så insåg jag att upplösningen och bildhastigheten var extremt dålig. Detta skulle resultera i att bilen var nästan omöjlig att köra ordentligt när man körde den via kameran på hemsidan. Därför valde jag till slut att använda mig av Iriun Webcam för att få bättre prestanda. 


I produktplaneringen syns det även att jag tänkte använda mig av en MQTT broker för att sköta den trådlösa styrningen. Men eftersom jag redan har använt det i robotprojektet i ettan så bestämde jag mig för att välja firebase för att både utmana mig själv, samt för att detta projekt inte skulle likna det föregående projektet allt för mycket.

## Videovisning 


## Bilder


#### Styrning Via Hemsida


För att styra bilen från hemsidan kan man antingen klicka på knapparna alternativt använda wasd

<img src="https://github.com/abbseblin/Robotic-Car-G29-main/blob/master/images/Hemsida1.png" alt="drawing" height="400"/>


#### Kameravy


<img src="https://github.com/abbseblin/Robotic-Car-G29-main/blob/master/images/Hemsida2.png" alt="drawing" height="400"/>
