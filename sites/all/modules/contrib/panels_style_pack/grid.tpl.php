<table>
  <tbody>
    <?php foreach ($row as $row_number => $columns): ?>
      <tr>
        <?php foreach ($columns as $column_number => $item): ?>
          <td>
            <?php print $item; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>