
let path = require('path');

let device = "j722s";


const files_c75 = {
    common: [
        "udma.c",
        "dmautils_autoincrement_3d.c",
        "dmautils_autoincrement_3d_hostemu.c",
        "csl_dru.c"
    ],
};

const filedirs = {
    common: [
        "udma_standalone",
        "src",
        "udma_standalone/src",
        "csl/dru/v0/priv",
    ],
};

const defines_c75 = {
    common: [
        "MCU_PLUS_SDK",
        "MAKEFILE_BUILD",
        "BUILD_C7X_1",
        "BUILD_C7X",
        "UDMA_CFG_ASSERT_ENABLE",
        "UDMA_CFG_PRINT_ENABLE",
        "DMA_UTILS_STANDALONE ",
        "SOC_J722S",
    ],
};

const buildOptionCombos = [
    { device: device, cpu: "c75ss0-0", cgt: "ti-c7000"},
    { device: device, cpu: "c75ss1-0", cgt: "ti-c7000"},
    /*{ device: device, cpu: "c75ssx-0", cgt: "ti-c7x-hostemu"},*/
];


function getComponentProperty() {
    let property = {};


    property.dirPath = path.resolve(__dirname, "..");
    property.type = "library";
    property.name = "dmautils";
    property.isInternal = false;

    property.buildOptionCombos = buildOptionCombos;

    return property;
}

function getComponentBuildProperty(buildOption) {
    let build_property = {};

    build_property.filedirs = filedirs;

    if(buildOption.cpu.match(/c75*/)) {
        build_property.files = files_c75;
        build_property.defines = defines_c75;
    }

    return build_property;
}

module.exports = {
    getComponentProperty,
    getComponentBuildProperty,
};
