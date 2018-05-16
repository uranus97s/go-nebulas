"use strict"

var kvStore = function() {
};

var contractInterface = {
    save: function() {
    },
    get: function() {
    },
}


kvStore.prototype = {
    init: function() {
        //
    },

    testTpsForNormalCall: function() {
        
    },

    testTpsForMutiNvm: function(address) {
        console.log(address);
        var contractInterface = {
            testTps: function(){

            },
        };
        var v = Blockchain.transaction.value;
        var real_kv = new Blockchain.Contract(address, contractInterface);
        return real_kv.value(1).testTps();
    },

    save: function(address, key, value) {

        var real_kv  = new Blockchain.Contract(address, contractInterface);
        
        // if (Blockchain.transaction.value < 2) {
        //     throw("nas is not enough")
        // }

        var args = new Array();
        args[0] = key;
        args[1] = value;
        // real_kv.value(2000000000000000000).call('save', JSON.stringify(args));
        real_kv.value(2000000000000000000).save(key, value);
    },

    saveByCall: function(address, key, value) {

        var real_kv  = new Blockchain.Contract(address, contractInterface);
        
        // if (Blockchain.transaction.value < 2) {
        //     throw("nas is not enough")
        // }

        var args = new Array();
        args[0] = key;
        args[1] = value;
        real_kv.value(2000000000000000000).call('save', JSON.stringify(args));
        // real_kv.value(2000000000000000000).save(key, value);
    },

    safeSave : function(address, key, value) {

        var real_kv  = new Blockchain.Contract(address, contractInterface);
        
        // if (Blockchain.transaction.value < 2) {
        //     throw("nas is not enough")
        // }

        var args = new Array();
        args[0] = key;
        args[1] = value;
        // real_kv.value(2000000000000000000).call('save', JSON.stringify(args));
        try {
            real_kv.value(2000000000000000000).save(key, value);
        } catch(err) {
            console.log("=========",err);
            var value = Blockchain.transaction.value;
            real_kv.value(value).save(key, value);
        }
    },

    get: function(address, key) {
        var real_kv = new Blockchain.Contract(address, contractInterface);
        var args = new Array();
        args[0] = key;
        return real_kv.get(key)
        //return real_kv.call('get', JSON.stringify(args));
    },

    testTryCatch: function(address) {
        var contractInterface = {
            throwErr: function() {
            }
        }
        var real_kv = new Blockchain.Contract(address, contractInterface);

        try {
            real_kv.throwErr();
        } catch(err) {
            return;
        }
    },

    testWrongInterfaceNotFunc: function(address) {
        var contractInterface = {
            save: function() {
            },
            wiki:0,
            testTryCatch: function() {
            }
        }
        var real_kv = new Blockchain.Contract(address, contractInterface);

    },

    testWrongInterfaceMissFunc: function(address) {
        var contractInterface = {
            save: function() {
            },
            wiki: function() {

            },
            testTryCatch: function() {
            }
        }
        var real_kv = new Blockchain.Contract(address, contractInterface);
        return real_kv.wiki();
    }
}

module.exports = kvStore;