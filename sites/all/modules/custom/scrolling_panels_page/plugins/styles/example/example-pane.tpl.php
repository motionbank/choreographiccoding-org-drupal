<?php
	drupal_add_css( 
		drupal_get_path('module','example_styles') . '/plugins/styles/example/example.css', 
		array('group' => CSS_DEFAULT, 
		'every_page' => TRUE));
?><div class="example-pane">
	<?php if (isset($content->title)): ?>
		<h2 class="pane-title <?php print (isset($settings['top_color'])) ? $settings['top_color'] : 'blue'; ?>"><?php print $content->title; ?></h2>
	<?php endif ?>
	<div class="pane-content">
		<?php print render($content->content); ?>
	</div>
</div>