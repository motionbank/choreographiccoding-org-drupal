<?php
	$module_path = drupal_get_path('module','scrolling_panels_page');
	drupal_add_css( $module_path . '/plugins/styles/sliding_region/sliding-region.css' );
	drupal_add_js(  $module_path . '/plugins/styles/sliding_region/sliding-region.js' );
?>
<div class="region-slideshow region">
	<?php print render( $content ); ?>
</div>