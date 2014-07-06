<?php
	// http://dustinbons.com/panels-styles-plugin-drupal-7
	drupal_add_css(
		drupal_get_path( 'module', 'scrolling_panels_page' ) .'/plugins/styles/example/example.css', 
		array(
			'group' => CSS_DEFAULT, 
			'every_page' => TRUE
		) 
	);
?>
<div class="example-region">
	<?php if ( $content ) : ?>
		<?php print render( $content ); ?>
	<?php else : ?>
		No content!
	<?php endif; ?>
</div>