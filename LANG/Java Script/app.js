function freezeObj(){
    "use strict";
    const MATH_CONSTANT = {
        PI: 3.14
    };

    Object.freeze(MATH_CONSTANT);

    try{
        MATH_CONSTANT.PI = 99;
    }

    catch(ex){
        console.log(ex);
    }

    return MATH_CONSTANT.PI;
}

const PI  = freezeObj();