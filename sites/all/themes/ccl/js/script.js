
// (function ($, Drupal, window, document, undefined) {
// // To understand behaviors, see https://drupal.org/node/756722#behaviors
// Drupal.behaviors.my_custom_behavior = {
//   attach: function(context, settings) {
//     // Place your code here.
//   }
// };
// })(jQuery, Drupal, this, this.document);

jQuery(function(){
	jQuery('span.at').html('@').removeClass('at');
	jQuery('span.dot').html('.').removeClass('dot');
});