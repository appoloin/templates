module.exports = {
    "env": {
        "browser": true,
        "node": true,
        "mocha":true,
        "es6": true,
    },
    "plugins": [
        "mocha",
        "prettier"
    ],
    "extends": [
        "prettier",
        "eslint:recommended",
        "plugin:prettier/recommended",
    ],
    "rules": {
        "prettier/prettier": ["error", {
            "printWidth": 100,
            "useTabs": true,
            "tabWidth":4,
        }],
        "no-warning-comments": [ "warn", {
            "terms": [ "TODO", "FIXME" ],
            "location": "start"
        }],
        "camelcase": "warn",
    },
};