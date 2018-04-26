const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const WebpackCleanPlugin = require("webpack-clean-plugin");
const FaviconsWebpackPlugin = require("favicons-webpack-plugin");
const OptimizeCSSAssetsPlugin = require("optimize-css-assets-webpack-plugin");
const UglifyJsPlugin = require("uglifyjs-webpack-plugin");

module.exports = {
	entry: {
		app: "./src/js/index.js",
		about: "./src/js/about.js"
	},
	plugins: [
		new FaviconsWebpackPlugin({
			logo: "./src/images/themeisle.svg",
			icons: {
				android: false,
				appleIcon: false,
				appleStartup: false,
				favicons: true,
				firefox: false,
				windows: false
			},
			prefix: "./img/Icons-[hash]/"
		}),
		new WebpackCleanPlugin({
			on: "emit",
			path: ["./dist"]
		}),
		new MiniCssExtractPlugin({
			filename: "./style/[name].css",
			chunkFilename: "[id].css"
		}),
		new HtmlWebpackPlugin({
			template: "./src/template/index.ejs",
			title: "Home",
			chunks: ["app"],
			minify: {
				html5: true,
				collapseWhitespace: true,
				minifyCSS: true,
				minifyJS: true,
				minifyURLs: false,
				removeAttributeQuotes: true,
				removeComments: true,
				removeEmptyAttributes: true,
				removeOptionalTags: true,
				removeRedundantAttributes: true,
				removeScriptTypeAttributes: true,
				removeStyleLinkTypeAttributese: true,
				useShortDoctype: true
			}
		}),
		new HtmlWebpackPlugin({
			template: "./src/template/about.ejs",
			filename: "about.html",
			title: "About",
			chunks: ["about"],
			minify: {
				html5: true,
				collapseWhitespace: true,
				minifyCSS: true,
				minifyJS: true,
				minifyURLs: false,
				removeAttributeQuotes: true,
				removeComments: true,
				removeEmptyAttributes: true,
				removeOptionalTags: true,
				removeRedundantAttributes: true,
				removeScriptTypeAttributes: true,
				removeStyleLinkTypeAttributese: true,
				useShortDoctype: true
			}
		}),
		new HtmlWebpackPlugin({
			template: "./src/template/anotherPage.ejs",
			filename: "anotherPage.html",
			title: "Another Page",
			chunks: ["about"],
			minify: {
				html5: true,
				collapseWhitespace: true,
				minifyCSS: true,
				minifyJS: true,
				minifyURLs: false,
				removeAttributeQuotes: true,
				removeComments: true,
				removeEmptyAttributes: true,
				removeOptionalTags: true,
				removeRedundantAttributes: true,
				removeScriptTypeAttributes: true,
				removeStyleLinkTypeAttributese: true,
				useShortDoctype: true
			}
		}),
		new HtmlWebpackPlugin({
			template: "./src/template/anotherPage2.ejs",
			filename: "anotherPage2.html",
			title: "Another Page 2",
			chunks: ["about"],
			minify: {
				html5: true,
				collapseWhitespace: true,
				minifyCSS: true,
				minifyJS: true,
				minifyURLs: false,
				removeAttributeQuotes: true,
				removeComments: true,
				removeEmptyAttributes: true,
				removeOptionalTags: true,
				removeRedundantAttributes: true,
				removeScriptTypeAttributes: true,
				removeStyleLinkTypeAttributese: true,
				useShortDoctype: true
			}
		})
	],
	output: {
		filename: "js/[name].bundle.js",
		path: path.resolve(__dirname, "dist")
	},
	//devtool: "inline-source-map",
	devServer: {
		contentBase: "./dist",
		compress: true,
		port: 9000,
		publicPath: "/"
	},
	module: {
		rules: [
			{
				//css sacc
				test: /\.s?[ac]ss$/,
				use: [MiniCssExtractPlugin.loader, "css-loader", "sass-loader"]
			},
			{
				//images
				test: /\.(png|svg|jpg|gif)$/,
				use: {
					loader: "file-loader",
					options: {
						name: "[name].[ext]",
						outputPath: "./img/"
					}
				}
			},
			{
				//fonts
				test: /\.(woff|woff2|eot|ttf|otf)$/,
				use: {
					loader: "file-loader",
					options: {
						name: "[name].[ext]",
						outputPath: "./fonts/"
					}
				}
			},
			{
				test: /\.(html|htm)$/,
				use: [
					{
						loader: "html-loader",
						options: { minimize: true }
					}
				]
			},
			{
				test: /\.(js|jsx)$/,
				exclude: /(node_modules|bower_components)/,
				use: [
					{
						loader: "babel-loader",
						options: {
							presets: ["env"]
						}
					}
				]
			}
		]
	},
	optimization: {
		minimizer: [
			new UglifyJsPlugin({
				cache: true,
				parallel: true,
				sourceMap: false // set to true if you want JS source maps
			}),
			new OptimizeCSSAssetsPlugin({})
		]
	}
};
