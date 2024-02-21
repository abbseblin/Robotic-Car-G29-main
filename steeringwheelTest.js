import * as g from 'logitech-g29';

g.connect(function(err) {
    g.on('pedals-gas', function(val) {
        g.leds(val)
    })
})